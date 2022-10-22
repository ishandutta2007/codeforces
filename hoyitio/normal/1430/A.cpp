#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e3 + 50;
int vis[maxn];
int a[maxn][3];
int main()
{
    int cnt = 0;
    for(int i= 0;i*3 < maxn;++i){
        for(int j = 0; i*3+j*5 < maxn; ++j){
            for(int k = 0; i*3+j*5+k*7 < maxn; ++k){
                int p = i*3+j*5+k*7;
                if(!vis[p]){
                    vis[p] = 1;
                    a[p][0] = i, a[p][1] = j, a[p][2] = k;
                }
            }
        }
    }
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        if(!vis[n]) printf("-1");
        else printf("%d %d %d", a[n][0], a[n][1], a[n][2]);
        printf("\n");
    }
}