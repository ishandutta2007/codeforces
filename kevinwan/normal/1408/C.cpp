#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
double t1[mn],t2[mn],d[mn];
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
    while(tc--){
    	int n;
    	cin>>n;
    	for(int i=0;i<=n+5;i++)t1[i]=t2[i]=d[i]=0;
    	cin>>d[n+1];
    	for(int i=1;i<=n;i++)cin>>d[i];
    	for(int i=1;i<=n+1;i++)t1[i]=t1[i-1]+(d[i]-d[i-1])/i;
    	for(int i=n;i>=0;i--)t2[i]=t2[i+1]+(d[i+1]-d[i])/(n+1-i);
    	for(int i=1;i<=n+1;i++){
    		if(t1[i]>t2[i]){
    			double dt=t2[i-1]-t1[i-1];
    			double dis=dt*(n+2-i);
    			printf("%.20lf\n",t1[i-1]+dis/(n+2));
    			break;
    		}
    	}
    }
}