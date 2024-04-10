#include <cstdio>
#include <algorithm>
using namespace std;

struct point{
    int x;
    int diff;
    bool operator<(const point &a) const {
        if(x == a.x) return diff > a.diff;
        return x < a.x;
    }
}a[2000010];

int n, k, q, w;
int cur, cnt, ans[1000010][2];
bool par = false;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &q, &w);
        a[2 * i] = {q, 1};
        a[2 * i + 1] = {w, -1};
    }
    sort(a, a + 2 * n);
    for(int i = 0; i < 2 * n; i++){
        cur += a[i].diff;
        if(cur >= k && !par){
            ans[cnt][0] = a[i].x;
            par = !par;
        }
        else if(cur < k && par){
            ans[cnt++][1] = a[i].x;
            par = !par;
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}