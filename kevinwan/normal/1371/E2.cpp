#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int a[mn],p[mn];
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int n,p;
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int lo=0xc0c0c0c0,hi=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		lo=max(lo,a[i]-i);
		hi=min(hi,((i+p-1<n)?a[i+p-1]:0x3f3f3f3f)-1-i);
		cerr<<lo<<' '<<hi<<'\n';
	}
	lo=max(lo,1);
	printf("%d\n",max(hi-lo+1,0));
	for(int i=lo;i<=hi;i++)printf("%d ",i);
}