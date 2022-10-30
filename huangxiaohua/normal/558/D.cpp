#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<pair<ll,ll> >s;

int i,j,k,n,m,t;
ll l,r,x,y,res;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%lld%lld%d",&j,&l,&r,&k);
		if(!k){
			for(k=j;k<n;k++){l*=2;r=r*2+1;}
			s.insert({l,r});
		}
		else{
			x=(1ll<<(j-1));y=l-1;
			if(l!=x){for(k=j;k<n;k++){x*=2;y=y*2+1;}s.insert({x,y});}
			x=r+1;y=(1ll<<(j))-1;
			if(r!=y){for(k=j;k<n;k++){x*=2;y=y*2+1;}s.insert({x,y});}
		}
	}
	s.insert({(1ll<<n),(1ll<<n)});
	l=r=(1ll<<(n-1))-1;
	for(auto [i,j]:s){
		if(i<=r+1){r=max(r,j);continue;}
		if(i>r+2||res){puts("Data not sufficient!");return 0;}
		res=r+1;l=i;r=j;continue;
	}
	if(!res){puts("Game cheated!");}
	else{printf("%lld",res);}
}