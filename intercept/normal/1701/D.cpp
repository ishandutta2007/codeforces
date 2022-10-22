#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5e5+9;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)rex=1ll*rex*x%mod;
	return rex;
}
int n;
int p[M];
vector<pii>b[M];
set<pii>s;
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)b[i].clear();
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		if(!k)b[i+1].eb(n,i);
		else b[i/(k+1)+1].eb(i/k,i);
	}
	for(int x=1;x<=n;++x){
		for(auto o:b[x]){
			s.insert(o);
		}
		auto o=*s.begin();
		s.erase(o);
		p[o.se]=x;
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",p[i]," \n"[i==n]);
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
6 6
1 2 3 4 5 6
*/