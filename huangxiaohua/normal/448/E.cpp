#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,set<ll> >mp;
int i,j,k,it,ii,s[100500],tmp,pre,sb;
ll n,t,f[100500];
vector<pair<ll,ll> >v1,v2;

int main(){
	scanf("%lld%lld",&n,&t);
	if(n==1)return puts("1"),0;
	if(t>=100000){
		for(i=1;i<=min(100000ll,t);i++){printf("1 ");}return 0;
	}
	v1.push_back({n,1});
	while(t--){
		pre=0;
		for(auto [i,j]:v1){
			if(mp[i].empty()){
				for(ll k=1;k*k<=i;k++){if(!(i%k)){mp[i].insert(k);mp[i].insert(i/k);}}
			}
			for(auto k:mp[i]){
				if(k==1)continue;
				pre++;
				if(pre+j<=100000)v2.push_back({k,pre+j});
				else sb=1;
			}
		}
		swap(v1,v2);v2.clear();
	}
	for(auto [i,j]:v1){f[j]=i;}
	;
	for(i=1;i<=100000;i++){
		printf("%lld ",(!f[i])?1:f[i]);
		if(f[i]==n)break;
	}
}