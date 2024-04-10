#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int inv2=(Mod+1)/2;
ll l,r,p[64],sum[64];
ll calc(ll x,ll v){//x,x+2,x+4,...,x+2*v
	//cerr<<x<<'#'<<x+v+v<<endl;
	x%=Mod; v%=Mod;
	return (x+x+v+v)%Mod*(v+1)%Mod*inv2%Mod;
}
ll solve(ll x){
	if (!x) return 0;
	int mul=0;
	while (x>=(1ll<<mul)) mul++;
	mul--;
	
	//cerr<<mul<<' '<<p[mul]<<endl;
	//2^mul..x
	return calc(p[mul],x-(1ll<<mul))+sum[mul-1];
}
int main(){
	p[0]=1; sum[0]=1;
	p[1]=2; sum[1]=7;
	for (int i=2;i<=60;i++){
		if (i&1) p[i]=p[i-1]*2;
		else p[i]=p[i-1]*2-1;
		sum[i]=(sum[i-1]+calc(p[i],(1ll<<i)-1))%Mod;
	}
	
	cin>>l>>r;
	cout<<(solve(r)-solve(l-1)+Mod)%Mod<<endl;
	return 0;
}