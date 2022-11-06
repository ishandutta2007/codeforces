#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1510,mo=1e9+7;
ll f[N][N],p[N],n,m;
ll p0,k,a,b,jc[100100],ny[100100];
ll power(ll a,ll b=mo-2){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
ll C(int n,int m){
	return ny[m]*ny[n-m]%mo*jc[n]%mo;
}
void move(ll &a,ll b){
	a=(a+b)%mo;
}
int main(){
	cin>>n>>m>>a>>b>>k;
	p0=a*power(b)%mo;
	jc[0]=1;
	for (int i=1;i<=k;i++)jc[i]=jc[i-1]*i%mo;
	ny[k]=power(jc[k]);
	for (int i=k;i>=1;i--)ny[i-1]=ny[i]*i%mo;
	for (int i=0;i<=m&&i<=k;i++){
		p[i]=C(k,i)*power(p0,i)%mo*power(mo+1-p0,k-i)%mo;
	}
	f[0][m]=1;
	for (int i=1;i<=n;i++){
		ll sum1=0,sum2=0;
		for (int j=1;j<=m;j++){
			move(sum1,p[j-1]);
			move(sum2,p[j-1]*f[i-1][j-1]);
			move(f[i][j],f[i][j-1]+(sum1*(f[i-1][m]-f[i-1][m-j]+mo)-sum2+mo)%mo*p[m-j]);
		}
	}
	cout<<f[n][m]<<endl;
}