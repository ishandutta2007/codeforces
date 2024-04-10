#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;

class edge{
      public:
      int l, r;
      edge(int l_ = 0, int r_ = 0){l = l_; r = r_;}
      bool in(edge x){
           return l <= x.l && r >= x.r;
      }
};

int n, m;
int a[3005], b[3005], l[3005], r[3005];

vector < pair < edge, int > > v[1005];

vector < int > values;

bool bio[1005];
bool dfs(int pos, edge x){
     if (pos == n) return true;
     if (bio[pos]) return false;
     bio[pos] = true;
     for (int i = 0; i < v[pos].size(); ++i){
         if (v[pos][i].x.in(x)) if (dfs(v[pos][i].y, x)) return true;
     }
     return false;
}

bool att(int x, int y){
     for (int i = 0; i <= n; ++i) bio[i] = false;
     return dfs(1, edge(x, y));
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        scanf("%d%d%d%d", a + i, b + i, l + i, r + i);
        v[a[i]].push_back(make_pair(edge(l[i], r[i]), b[i]));
        v[b[i]].push_back(make_pair(edge(l[i], r[i]), a[i]));
        values.push_back(l[i]);
    }
    //sort(values.begin(), values.end());
    int rez = -1;
    for (int i = 0; i < values.size(); ++i){
        if (!att(values[i], values[i])) continue;
        int lo = values[i], hi = 1000000, mid = (lo + hi + 1) / 2;
        while (lo != hi){
              if (att(values[i], mid)){
                 lo = mid;
              }
              else {
                   hi = mid - 1;
              }
              mid = (lo + hi + 1) / 2;
        }
        if (lo - values[i] + 1 > rez) rez = lo - values[i] + 1;
    }
    if (rez == -1) printf("Nice work, Dima!\n");
    else printf("%d\n", rez);
    return 0;
}