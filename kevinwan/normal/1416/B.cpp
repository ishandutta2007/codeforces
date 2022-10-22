#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll a[mn];
struct three{ll a,b,c;};
vector<three>v;
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    for(int tcc=1;tcc<=tc;tcc++){
        int n;
        cin>>n;
        v.clear();
        for(int i=0;i<=n+1;i++);
        ll sum=0;
        for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        if(sum%n){printf("-1\n");continue;}
    	ll t=sum/n;
    	for(int i=2;i<=n;i++){
    		ll ex=(i-a[i]%i)%i;
    		v.push_back({1,i,ex});
    		a[1]-=ex,a[i]+=ex;
    		ll num=a[i]/i;
    		v.push_back({i,1,num});
    		a[i]-=num*i,a[1]+=num*i;
    	}
    	for(int i=2;i<=n;i++)v.push_back({1,i,t});
    	printf("%d\n",v.size());
    	for(three t:v)printf("%lld %lld %lld\n",t.a,t.b,t.c);
    }
}