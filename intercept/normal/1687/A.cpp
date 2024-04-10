#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int a[M];
ll p[M];
void work(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(k>n)a[i]+=k-n;
	}
	k=min(k,n);
	ll ans=0;
	for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;++i){
		if(i>=k)ans=max(ans,p[i]-p[i-k]);
	}
	cout<<ans+1ll*k*(k-1)/2<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}