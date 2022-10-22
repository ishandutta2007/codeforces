#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
int a[1000009];
void work(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	ll ans=0;
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=1;i<n;++i){
		ans-=1ll*(a[i+1]-a[i])*i*(n-i);
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
1000000000 1000000000 
*/