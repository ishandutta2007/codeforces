#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int main()
{
    int T; cin>>T;
    while(T--){
        int x, y; scanf("%d%d", &x, &y);
        int t = min(x, y);
        int ans = 2*t;
        x -= t; y -= t;
        if(x < y) swap(x, y);
        if(x){
            ans ++; x--;
            ans += 2*x;
        }printf("%d\n", ans);
    }
}