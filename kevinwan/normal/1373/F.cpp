#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll a[mn],b[mn],ta[mn];
int n;
bool check1(ll x){
	for(int i=0;i<n;i++)ta[i]=a[i];
	ta[0]=max(0LL,ta[0]-x);
	for(int i=0;i<n-1;i++){
		if(ta[i]>b[i])return 0;
		ta[i+1]-=b[i]-ta[i];
		ta[i+1]=max(ta[i+1],0LL);
		ta[i]=0;
	}
	return 1;
}
bool check2(ll x){
	for(int i=0;i<n;i++)ta[i]=a[i];
	ta[0]=max(0LL,ta[0]-x);
	for(int i=0;i<n-1;i++){
		if(ta[i]>b[i])return 0;
		ta[i+1]-=b[i]-ta[i];
		ta[i+1]=max(ta[i+1],0LL);
		ta[i]=0;
	}
	return ta[n-1]<=b[n-1]-x;
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
   	int tc;
   	cin>>tc;
   	while(tc--){
   		cin>>n;
   		for(int i=0;i<n;i++)cin>>a[i];
   		for(int i=0;i<n;i++)cin>>b[i];
   		ll cur=-1;
   		for(ll i=1LL<<30;i;i>>=1){
   			if(cur+i>b[n-1])continue;
   			if(!check1(cur+i))cur+=i;
   		}
   		cur++;
   		if(cur<=b[n-1]&&check2(cur))printf("YES\n");
   		else printf("NO\n");
   	}
}