#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e3 + 5;
char mp[maxn][maxn];
int n;
int L[maxn],R[maxn],U[maxn],D[maxn];
const int inf = 1e9;
int sol(int dd){
    fors(i,0,n+1) L[i]=D[i] = inf, R[i] = U[i] = -inf;
    int tl, tr, td, tu;
    tl = td = inf;
    tr = tu = -inf;
    fors(i,1,n+1){
        fors(j,1,n+1){
            if(mp[i][j]-'0' == dd){
                L[i] = min(L[i], j);
                D[j] = min(D[j], i);
                R[i] = max(R[i], j);
                U[j] = max(U[j], i);
                tl = min(tl, L[i]);
                td = min(td, D[j]);
                tr = max(tr, R[i]);
                tu = max(tu, U[j]);
            }
        }
    }
    int ans = 0;
    fors(i,1,n+1){
        fors(j,1,n+1){
            int l = j, r = j;
            int d = i, u = i;
            l = min(L[i], l); r = max(r, R[i]);
            d = min(D[j], d); u = max(u, U[j]);

            ans = max(ans, (r-l)*(i-td));
            ans = max(ans, (r-l)*(tu-i));
            ans = max(ans, (u-d)*(j-tl));
            ans = max(ans, (u-d)*(tr-j));
        }
    }
    return ans;
}
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%d", &n);
        fors(i,1,n+1) scanf("%s", mp[i]+1);
        fors(i,0,10){
            if(i) printf(" ");
            printf("%d", sol(i));
        }printf("\n");
    }
}
/*
5
3
000
122
001
*/