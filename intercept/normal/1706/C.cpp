#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n;
int a[M];
ll p[M],s[M];
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=2;i<n;i+=2){
		p[i]=p[i-2];
		if(a[i]>a[i-1]&&a[i]>a[i+1])continue;
		p[i]+=max(a[i-1],a[i+1])+1-a[i];
	}
	ll ans;
	if(n&1)ans=p[n-1];
	else ans=p[n-2];
	if((n&1)==0){
		s[n+1]=0;
		for(int i=n-1;i>=2;i-=2){
			s[i]=s[i+2];
			if(a[i]<=a[i-1]||a[i]<=a[i+1])s[i]+=max(a[i-1],a[i+1])+1-a[i];
			ans=min(ans,p[i-3]+s[i]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
6
3 1 4 5 5 2
*/