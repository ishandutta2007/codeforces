#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=3e5+10;

int a[N],h[N],n,m=0;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n*n) scanf("%d",a+i);
    sort(a+1,a+n*n+1);
    FOR(i,1,n*n){
        a[++m]=a[i];
        int j=i;
        while (i<n*n&&a[i+1]==a[i]) i++;
        h[m]=i-j+1;
    }
}
void solve(){
    vector <int> ans;
    FORD(i,m,1) if (h[i]){
        int sum=0,num=0;
        for(auto x:ans) if (x%a[i]==0) sum++;
        while (1LL*(num+1)*(num+1+sum*2)<=h[i]) num++;
        for(auto x:ans){
            int idx=lower_bound(a+1,a+m+1,__gcd(a[i],x))-a;
            h[idx]-=2*num;
        }
        h[i]-=num*num;
//        h[i]=0;
//FOR(i,1,m) printf("%d ",h[i]);ENDL;
        FOR(j,1,num) ans.push_back(a[i]);
    }
//    FOR(i,1,m) printf("%d ",a[i]);ENDL;
//    FOR(i,1,m) printf("%d ",h[i]);ENDL;
    for(auto i:ans) printf("%d ",i);
}
int main(){
    prepare();
    solve();
}