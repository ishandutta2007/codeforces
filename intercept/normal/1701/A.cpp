#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)rex=1ll*rex*x%mod;
	return rex;
}
void work(){
	int rex=0;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			int x;
			cin>>x;
			rex+=x;
		}
	}
	if(rex==0)puts("0");
	else if(rex==4)puts("2");
	else puts("1");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}