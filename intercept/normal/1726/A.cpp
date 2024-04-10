#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
int n;
int a[2009];
void work(){
	cin>>n;
	int mi=1e9,ma=0;
	for(int i=1;i<=n;++i)cin>>a[i],mi=min(mi,a[i]),ma=max(ma,a[i]);
	int ans=0;
	for(int l=1,r=n;l<=n;++l,r=r%n+1){
		ans=max(ans,a[r]-a[l]);
	}
	ans=max(ans,a[n]-mi);
	ans=max(ans,ma-a[1]);
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}