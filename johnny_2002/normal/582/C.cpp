#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=2e5+10;

int n,m,a[N],h[N<<1];
vector <int> v[N];
void prepare(){
    scanf("%d",&n);
    REP(i,0,n) scanf("%d",a+i);
    REP(i,1,n) v[__gcd(i,n)].push_back(i);
}
ll solve(){
    ll ans=0;
    REP(clen,1,n) if (!v[clen].empty()){
        REP(st,0,clen){
            int maxi=a[st];
            for(int j=st;j<n;j+=clen) maxi=max(maxi,a[j]);
            for(int j=st;j<n;j+=clen) h[j]=a[j]>=maxi;
        }
        REP(i,n,n<<1) h[i]=h[i-n];
//        printf("%d\n",clen);
//        REP(j,0,n) printf("%d ",h[j]);ENDL;
        FORD(i,n*2-1,0) if (h[i]) h[i]+=h[i+1];
        REP(j,0,n) ans+=upper_bound(v[clen].begin(),v[clen].end(),h[j])-v[clen].begin();
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}