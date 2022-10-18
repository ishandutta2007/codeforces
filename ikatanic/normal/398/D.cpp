#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> edge;

const int K = 700;
const int MAXN = 50005;
const int MAXQ = 250005;
const int MAXE = 800004;

edge OE[MAXE];
edge E[MAXE];
bool on[MAXE];
int m;

int st[MAXN], sz[MAXN];

bool online[MAXN];

int cnt[MAXN];
int t[MAXQ], u[MAXQ], v[MAXQ];

int cookie;
int bio_ch[MAXN], bio_qr[MAXN];
int ch_i[MAXN], qr_i[MAXN];
int ch[MAXN], qr[MAXN];
int ch_cnt, qr_cnt;

int e[K][K];

void flipEdge(int a, int b) {
  edge p1 = {a, b}, p2 = {b, a};
  on[lower_bound(E, E + m, p1) - E] ^= 1;
  on[lower_bound(E, E + m, p2) - E] ^= 1;
}

int main(void) {
  int n, q;
  scanf("%d %d %d", &n, &m, &q);
  
  int o;
  scanf("%d", &o);
  REP(i, o) {
    int x;
    scanf("%d", &x); --x;
    online[x] = true;
  }
 
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    OE[i] = {x, y};
    E[2*i] = {x, y};
    E[2*i+1] = {y, x};
  }

  int om = m;
  REP(i, q) {
    char type[5];
    scanf("%s", type);
    
    if (type[0] == 'A' || type[0] == 'D') {
      scanf("%d %d", u+i, v+i); --u[i], --v[i];
      E[m*2] = {u[i], v[i]};
      E[m*2+1] = {v[i], u[i]};
      m++;
    } else {
      scanf("%d", u+i);
      --u[i];
    }

    string types = "FDCAO";
    t[i] = types.find(type[0]) - 2;
  }
  
  m = m*2;
  sort(E, E + m);
  m = (unique(E, E + m) - E);
  REP(i, om) flipEdge(OE[i].first, OE[i].second);
  
  int cur = -1;
  REP(i, n) sz[i] = 0;
  REP(i, m) {
    if (cur != E[i].first) {
      st[E[i].first] = i;
      cur = E[i].first;
    }
    sz[cur]++;
  }

  int last = 0;
  REP(i, q) {
    if (i%K == 0) {
      for (int j = last; j < i; ++j)
        if (t[j] == +1 || t[j] == -1) flipEdge(u[j], v[j]);
      
      REP(j, n) {
        cnt[j] = 0;
        for (int k = st[j]; k < st[j]+sz[j]; ++k)
          if (on[k] && online[E[k].second]) cnt[j]++;
      }

      // izvuci one koji mijenjaju online status u sljedecem bloku
      cookie++;
      ch_cnt = 0;
      for (int j = i; j < i+K && j < q; ++j)
        if (t[j] == -2 || t[j] == +2)
          if (bio_ch[u[j]] != cookie) {
            int x = u[j];
            bio_ch[x] = cookie;
            ch[ch_cnt] = x;
            ch_cnt++;
          }
      
      sort(ch, ch + ch_cnt);
      REP(i, ch_cnt) ch_i[ch[i]] = i;
      
      qr_cnt = 0;
      // izvuci one koji se kverijaju u sljedecem bloku
      for (int j = i; j < i+K && j < q; ++j)
        if (t[j] == 0)
          if (bio_qr[u[j]] != cookie) {
            int x = u[j];
            bio_qr[x] = cookie;
            qr[qr_cnt] = x;
            qr_i[x] = qr_cnt++;
            
            REP(i, ch_cnt) e[qr_i[x]][i] = 0;

            // izvuci edgeve prema ch, e[qr][ch]
            int ptr = 0;
            for (int k = st[x]; k < st[x]+sz[x]; ++k) 
              if (on[k]) {
                while (ptr < ch_cnt && ch[ptr] < E[k].second) ptr++;
                if (ptr < ch_cnt && E[k].second == ch[ptr]) e[qr_i[x]][ptr] = 1;
              }
          }
          
      last = i;
    }
    
    if (t[i] == -2 || t[i] == +2) {
      int x = u[i];
      REP(j, qr_cnt)
        if (e[j][ch_i[x]]) cnt[qr[j]] += t[i]/2;
      online[x] ^= 1;
    }
    
    if (t[i] == -1 || t[i] == +1) {
      int x = u[i], y = v[i];
      if (bio_qr[x] == cookie) cnt[x] += t[i]*online[y];
      if (bio_qr[y] == cookie) cnt[y] += t[i]*online[x];
      if (bio_qr[x] == cookie && bio_ch[y] == cookie) e[qr_i[x]][ch_i[y]] ^= 1;
      if (bio_qr[y] == cookie && bio_ch[x] == cookie) e[qr_i[y]][ch_i[x]] ^= 1;
    }

    if (t[i] == 0) printf("%d\n", cnt[u[i]]);
  }
  return 0;
}