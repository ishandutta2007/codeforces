#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define x first
#define y second

using namespace std;

class ev{ // id = -1 ako nije query, nenegativan inace
      public:
      int x, y, id;
      ev(int a = 0, int b = 0, int c = 0){x = a; y = b; id = c;}
      bool operator<(const ev &a) const {
           if (x != a.x) return x < a.x;
           return id > a.id;
      }
};

int tur[1 << 20]; int sz[1 << 20];
int slo, shi;
void add(int id = 1, int lo = 0, int hi = (1 << 19) - 1){
     if (lo > shi || hi < slo) return;
     if (lo >= slo && hi <= shi){tur[id] = sz[id]; return;}
     if (tur[id] == sz[id]) return;
     add(id * 2, lo, (lo + hi) / 2);
     add(id * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[id] = tur[id * 2] + tur[id * 2 + 1];
}
int sum(int id = 1, int lo = 0, int hi = (1 << 19) - 1){
    if (lo > shi || hi < slo) return 0;
    if (lo >= slo && hi <= shi) return tur[id];
    if (tur[id] == sz[id]){tur[id * 2] = sz[id * 2]; tur[id * 2 + 1] = sz[id * 2 + 1];}
    return sum(id * 2, lo, (lo + hi) / 2) + sum(id * 2 + 1, (lo + hi + 1) / 2, hi);
}

int n;
vector < pair < int, int > > v;
int out[200005];

set < int > S;
vector < int > ss;
map < int, int > M;

vector < ev > sw;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int a, b; // a=p, b=l
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a, b));
        S.insert(a);
        S.insert(a + b);
    }
    ss.push_back(0);
    for (set < int >::iterator it = S.begin(); it != S.end(); ++it) ss.push_back(*it);
    for (int i = 0; i < ss.size(); ++i) M[ss[i]] = i;
    //sz[1 << 19] = 0;
    for (int i = 0; i < ss.size() - 1; ++i) sz[(1 << 19) + i] = ss[i + 1] - ss[i]; // i-ti interval = [[i], [i+1]];
    for (int i = (1 << 19) - 1; i; --i) sz[i] = sz[i * 2] + sz[i * 2 + 1];
    for (int i = 0; i < n; ++i){
        int a = v[i].x; int b = a + v[i].y;
        sw.push_back(ev(M[a], M[b] - 1, -1));
    }
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        int x, y; scanf("%d%d", &x, &y); --x; --y;
        x = v[x].x; y = v[y].x;
        sw.push_back(ev(M[x], M[y] - 1, i));
    }
    sort(sw.begin(), sw.end());
    for (int i = sw.size() - 1; i >= 0; --i){
        int x = sw[i].x, y = sw[i].y, id = sw[i].id;
        if (id == -1){
           slo = x; shi = y; add(); continue;
        }
        slo = x; shi = y; out[id] = ss[y + 1] - ss[x] - sum();
    }
    for (int i = 0; i < q; ++i) printf("%d\n", out[i]);
    return 0;
}