#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mo=1e9+7,M=1e9;
struct int512{
	ll a[100100],l;
}a,b,c,ept;
ll a1[100100],b1[100100],c1[100100],t;
ll s1[100100],p,k,m10[21];
ll divide(int512 &a,ll b){
	ll r=0;
	for (ll i=a.l;i;i--){
		a.a[i]+=r*M;
		r=a.a[i]%b;
		a.a[i]/=b;
	}
	if (a.a[a.l]==0)a.l--;
	return r;
}
int check(char e){
	return '0'<=e&&e<='9';
}
int512 read(){
	int512 a=ept;
	char e;
	while (check(e=getchar())){
		a1[++t]=e-'0';
	}
	ll c=1,d=0;
	for (ll i=t;i;i--){
		a.a[c]+=a1[i]*m10[d];
		d++;
		if (d==9)d=0,c++;
	}
	a.l=c;
	return a;
}
//ll ept1[100000];
ll f[2][3333][2][2];
ll c2(ll x){return (x*x-(x-1)*x/2+mo)%mo;}
int main(){
	cin>>p>>k;
	scanf("\n");
	m10[0]=1;
	for (ll i=1;i<=13;i++)m10[i]=m10[i-1]*10;
	a=read();
	t=0;
	while (a.l)s1[++t]=divide(a,p);
	for (ll i=1;i+i<=t;i++){
		s1[i]^=s1[t-i+1];
		s1[t-i+1]^=s1[i];
		s1[i]^=s1[t-i+1];
	}
	f[0][0][0][1]=1;
	int _=0;
	for (ll i=1;i<=t;i++){
	_^=1;
	memset(f[_],0,sizeof f[_]);
	for (ll j=0;j<=i;j++){
		for (ll k=0;k<=1;k++){
			if (j<k)continue;
			ll a1=c2(s1[i]-k),a2=s1[i]-k+1,a3=(c2(p-k)-c2(s1[i]-k+1)+mo)%mo;
			ll a4=(c2(p+k-1)-c2(p+k-s1[i]-1)+mo)%mo,a5=(p-s1[i]+k-1)%mo,a6=c2(p-s1[i]+k-2);
			f[_][j][k][0]+=a1*(f[_^1][j-k][0][0]+f[_^1][j-k][0][1])%mo;
			f[_][j][k][0]+=a2*f[_^1][j-k][0][0]%mo,
			f[_][j][k][1]+=a2*f[_^1][j-k][0][1]%mo;
			f[_][j][k][0]+=a3*f[_^1][j-k][0][0]%mo;
			f[_][j][k][0]+=a4*(f[_^1][j-k][1][0]+f[_^1][j-k][1][1])%mo;
			f[_][j][k][0]+=a5*f[_^1][j-k][1][0]%mo,
			f[_][j][k][1]+=a5*f[_^1][j-k][1][1]%mo;
			f[_][j][k][0]+=a6*f[_^1][j-k][1][0]%mo;
			f[_][j][k][0]%=mo;
			f[_][j][k][1]%=mo;
		}
	}
	}
	ll ans=0;
	for (ll i=k;i<=t;i++)
	for (ll k=0;k<=1;k++)ans=(ans+f[_][i][0][k]+mo)%mo;
	cout<<ans<<endl;
}