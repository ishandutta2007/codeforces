#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e6 + 5;

int vis[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int x; scanf("%d", &x);
        int cur = 0;
        int k = 1;
        while(cur < x){
            cur += k;
            k++;
        }
        if(cur == x+1) printf("%d\n", k);
        else printf("%d\n", k-1);
    }
}