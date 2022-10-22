#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)rex=1ll*rex*x%mod;
	return rex;
}
bool vis[M];
vector<int>ans;
void work(){
	int n;
	ans.clear();
	cin>>n;
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int x=i;
			ans.eb(x);
			vis[x]=1;
			while(x*2<=n)x*=2,ans.eb(x),vis[x]=1;
		}
	}
	cout<<2<<endl;
	for(auto o:ans)cout<<o<<" ";
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}