#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=110+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn],c[mn],d[mn];
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
    	int n,k;
    	cin>>n>>k;
    	k--;
    	for(int i=0;i<n;i++)cin>>a[i];
    	vector<pii>d;
    	for(int i=1;i<n;i++)if(a[i]!=a[i-1])d.push_back({i,a[i]-a[i-1]});
    	if(!k){
    		if(d.size())printf("-1\n");
    		else printf("1\n");
    	}
    	else printf("%d\n",max(1,(int)(d.size()+k-1)/k));
    }
}