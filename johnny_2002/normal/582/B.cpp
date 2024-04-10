#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,m,T,a[N],p[N],base[N][N],mat[N][N],tmp[N][N],s[N];
void prepare(){
    scanf("%d%d",&n,&T);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=a[i];
    sort(p+1,p+n+1);
    m=unique(p+1,p+n+1)-p-1;
    FOR(i,1,n) a[i]=lower_bound(p+1,p+m+1,a[i])-p-1;
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
}
int solve(){
    REP(L,0,m)
        REP(R,L,m){
            int top=0;
            FOR(i,1,n) if (a[i]>=L&&a[i]<=R){
                int idx=upper_bound(s+1,s+top+1,a[i])-s;
                s[idx]=a[i];
                if (idx>top) top++;
            }
            base[L][R]=top;
        }
//    REP(L,0,m)
//        REP(R,0,m) cout<<base[L][R]<<" \n"[R==m-1];
    for(;T;T>>=1){
        if (T&1){
            REP(i,0,m)
                REP(j,0,m) tmp[i][j]=mat[i][j];
            REP(i,0,m)
                REP(j,i,m)
                    FOR(k,i,j) mat[i][j]=max(mat[i][j],tmp[i][k]+base[k][j]);
        }
        REP(i,0,m)
            REP(j,0,m) tmp[i][j]=base[i][j];
        REP(i,0,m)
            REP(j,i,m)
                FOR(k,i,j) base[i][j]=max(base[i][j],tmp[i][k]+tmp[k][j]);
//        REP(L,0,m)
//            REP(R,0,m) cout<<base[L][R]<<" \n"[R==m-1];
    }
    return mat[0][m-1];
}
int main(){
    prepare();
    cout<<solve();
}