#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int B=650;
const int M=2e5+9;
int n,k;
int a[M],b[M],ans[M];
int main(){
	cin>>n>>k;
	b[0]=1;
	for(int l=k;l<=k+B;++l){
		for(int i=0;i<=n;++i)a[i]=b[i];
		for(int i=0;i<=n;++i){
			if(i>=l)b[i]=(b[i-l]+a[i-l])%mod;
			else b[i]=0;
			ans[i]=(ans[i]+b[i])%mod;
		}
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	return 0;
}