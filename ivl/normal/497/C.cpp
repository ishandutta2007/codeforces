#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
#include <set>

using namespace std;

int n;
int a[100005], b[100005];
int m;
int c[100005], d[100005], k[100005];

vector < int > v;
bool cmp(int x, int y){
     int xl, yl;
     if (x > 0) xl = a[x]; else xl = c[-x];
     if (y > 0) yl = a[y]; else yl = c[-y];
     if (xl != yl) return xl < yl;
     if (x < 0 && y > 0) return true;
     return false;
}

int out[100005];
bool YES = true;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", a + i, b + i);
        v.push_back(i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", c + i, d + i, k + i);
        v.push_back(-i);
    }
    sort(v.begin(), v.end(), cmp);
    set < pair < int, int > > S;
    for (int i = 0; i < v.size(); ++i){
        int x = v[i];
        if (x < 0){
           S.insert(make_pair(d[-x], -x));
           continue;
        }
        set < pair < int, int > >::iterator it = S.lower_bound(make_pair(b[x], -1));
        if (it == S.end()){YES = false; break;}
        out[x] = it->y;
        if (--k[it->y] == 0) S.erase(it);
    }
    if (!YES){printf("NO\n"); return 0;}
    printf("YES\n");
    for (int i = 1; i <= n; ++i){
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}