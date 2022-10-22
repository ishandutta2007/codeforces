#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
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
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)cin>>a[i];
    	for(int i=0;i<n;i++)cin>>b[i];
    	for(int i=0;i<n;i++)cin>>c[i];
    	for(int i=0;i<n-1;i++){
    		d[i]=a[i];
    		if(i&&d[i]==d[i-1])d[i]=b[i];
    	}
    	if(a[n-1]!=d[n-2]&&a[n-1]!=d[0])d[n-1]=a[n-1];
    	else if(b[n-1]!=d[n-2]&&b[n-1]!=d[0])d[n-1]=b[n-1];
    	else d[n-1]=c[n-1];
    	for(int i=0;i<n;i++)printf("%d ",d[i]);
    	printf("\n");
    }
}