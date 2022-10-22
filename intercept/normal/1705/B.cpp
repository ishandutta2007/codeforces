#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n;
ll a[M];
void work(){
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n-1;++i){
		if(a[i]){
			if(!a[i+1])ans++;
			a[i+1]+=a[i];
		}
	}
	ans+=a[n-1];
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}