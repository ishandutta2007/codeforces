#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lint;

int n, m, x, y, a[1005][1005];
int pmin[1005][1005], pmin2[1005][1005];
lint s[1005][1005];
bool vis[1005][1005];

struct node{int sx, sy; lint val;};
bool cmp(node a, node b){
    return a.val != b.val ? (a.val < b.val) : (make_pair(a.sx,a.sy) < make_pair(b.sx,b.sy));
}

vector<node> v, v2;

int main(){
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d",&a[i][j]);
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        deque<int> dq, num;
        for (int j=1; j<=m; j++) {
            if(!num.empty() && num.front() == j-y){
                num.pop_front();
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() > a[i][j]) {
                dq.pop_back();
                num.pop_back();
            }
            dq.push_back(a[i][j]);
            num.push_back(j);
            if(j >= y) pmin[i][j - y + 1] = dq.front();
        }
    }
    for (int i=1; i<=m - y + 1; i++) {
        deque<int> dq, num;
        for (int j=1; j<=n; j++) {
            if(!num.empty() && num.front() == j-x){
                num.pop_front();
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() > pmin[j][i]) {
                dq.pop_back();
                num.pop_back();
            }
            dq.push_back(pmin[j][i]);
            num.push_back(j);
            if(j >= x) pmin2[j-x+1][i] = dq.front();
        }
    }
    for (int i=1; i<=n-x+1; i++) {
        for (int j=1; j<=m-y+1; j++) {
            v.push_back({i,j,s[i+x-1][j+y-1] - s[i-1][j+y-1] - s[i+x-1][j-1] + s[i-1][j-1] - 1ll * pmin2[i][j] * x * y});
        }
    }
    sort(v.begin(),v.end(),cmp);
    for (auto &i : v){
        if(vis[i.sx][i.sy] || vis[i.sx + x - 1][i.sy] || vis[i.sx][i.sy + y - 1] || vis[i.sx + x - 1][i.sy+y-1]) continue;
        for (int t=0; t<x; t++) {
            for (int j=0; j<y; j++) {
                vis[i.sx + t][i.sy + j] = 1;
            }
        }
        v2.push_back(i);
    }
    printf("%d\n",(int)v2.size());
    for (auto &i :v2){
        printf("%d %d %lld\n",i.sx,i.sy,i.val);
    }
}