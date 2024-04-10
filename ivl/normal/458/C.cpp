#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
#include <map>

using namespace std;

pair < int, int > add(pair < int, int > a, pair < int, int > b){return make_pair(a.x + b.x, a.y + b.y);}
pair < int, int > tur[1 << 18];
int sp, sv;
void set(int pos = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > sp || hi < sp) return;
     if (lo == hi){
        tur[pos] = make_pair(sv, 1);
        return;
     }
     set(pos * 2, lo, (lo + hi) / 2);
     set(pos * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[pos] = add(tur[pos * 2], tur[pos * 2 + 1]);
}
int ask(int sq, int pos = 1, int lo = 0, int hi = (1 << 17) - 1){
    if (sq <= 0) return 0;
    if (lo == hi) return tur[pos].x;
    if (tur[pos * 2].y <= sq) return tur[pos * 2].x + ask(sq - tur[pos * 2].y, pos * 2 + 1, (lo + hi + 1) / 2, hi);
    else return ask(sq, pos * 2, lo, (lo + hi) / 2);
}

int n;
int a[100005], b[100005];
int cnt;

vector < int > nec[100005];
int nec_sum;
int nec_cnt;
vector < int > nec_active;

void add_nec(int a, int b){
     nec_sum += b;
     ++nec_cnt;
     nec[a].push_back(b);
     if (nec[a].size() == 1) nec_active.push_back(a);
}

int rem_nec(int a){
    --nec_cnt;
    nec_sum -= nec[a].back();
    nec[a].pop_back();
    return nec[a].size();
}

map < pair < int, int >, int > M;
void build_map(){
     vector < pair < int, int > > v;
     for (int i = 0; i < n; ++i) v.push_back(make_pair(b[i], a[i]));
     sort(v.begin(), v.end());
     for (int i = 0; i < v.size(); ++i) M[make_pair(v[i].y, v[i].x)] = i;
}

void m_add(int a, int b){
     int x = M[make_pair(a, b)]--;
     sp = x;
     sv = b;
     set();
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", a + i, b + i);
        if (a[i] == 0){++cnt; --n; --i; continue;}
        add_nec(a[i], b[i]);
    }
    build_map();
    for (int i = 0; i <= 100000; ++i) sort(nec[i].begin(), nec[i].end());
    int r = 2000000000;
    for (int i = 1; i <= 100000; ++i){
        //printf("%d\n", i);
        int sq = i - nec_cnt - cnt;
        r = min(r, nec_sum + ask(sq));
        //if (i <= n) printf("%d (sq = %d, cnt = %d, nec_cnt = %d)\n", r, sq, cnt, nec_cnt);
        static vector < int > v2;
        v2.clear();
        for (int j = 0; j < nec_active.size(); ++j){
            int x = nec_active[j];
            int y = nec[x].back();
            if (rem_nec(x) != 0) v2.push_back(x);
            m_add(x, y);
        }
        nec_active = v2;
    }
    printf("%d\n", r);
    return 0;
}