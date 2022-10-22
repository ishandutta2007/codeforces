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
int p[M];
int n,m;
bool check(int x){
	ll rex=0;
	for(int i=1;i<=n;++i){
		if(x<=p[i])rex+=p[i]-x;
		else {
			rex-=(x-p[i])/2;
		}
	}
	return rex<=0;
}
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)p[i]=0;
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		p[x]++;		
	}
	int l=1,r=m*2;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
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