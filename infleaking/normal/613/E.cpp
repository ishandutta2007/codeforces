#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=3010,mo=1e9+7,M=23333333333333333,step=31;
int f[N][N][2],n,m;
char s[2][N],t[N];
ll pw[N],ny[N];
ll mul(ll a,ll b,ll p=M){
	ll c=(long double)a*b/p,z=a*b-c*p;
	if (z<0)z+=M;
	if (z>M)z-=M;
	return z;
}
ll power(ll a,ll b=M-2){
	ll ans=1;
	while (b){
		if (b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}return ans;
}
struct hash1{
	ll a[N],b[N],n;
	void build(int _n,char *s){
		n=_n;
		for (int i=1;i<=n;i++)
			a[i]=(a[i-1]+(s[i]-'a'+1)*pw[i])%M,
			b[i]=(b[i-1]*step+(s[i]-'a'+1))%M;
	}
	ll query(int l,int r){
		return mul((a[r]-a[l-1]+M)%M,ny[l]);
	}
	ll iquery(int l,int r){
		return (b[r]-mul(b[l-1],pw[r-l+1])+M)%M;
	}
}h[2],g;
void prep(){
	pw[0]=ny[0]=1;
	ny[1]=power(step);
	for (int i=1;i<=n||i<=m;i++)
		ny[i]=mul(ny[i-1],ny[1]),pw[i]=pw[i-1]*step%M;
}
void move(int &a,int b){
	a=(a+b)%mo;
}
int ans;
void dp(){	
	h[0].build(n,s[0]);
	h[1].build(n,s[1]);
	g.build(m,t);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i&&j+j<=m;j++){
			if (h[1].iquery(i-j+1,i)==g.query(1,j)&&h[0].query(i-j+1,i)==g.query(j+1,2*j))
				move(f[i][2*j][0],1);
			if (h[0].iquery(i-j+1,i)==g.query(1,j)&&h[1].query(i-j+1,i)==g.query(j+1,2*j))
				move(f[i][2*j][1],1);
		}
//		for (int j=1;j<=i&&j+j<m;j++){
//			if (n-2*j<i)continue;
//			if (h[1].iquery(i-j+1,i+(m-2*j))==g.query(1,m-j)&&h[0].query(i-j+1,i)==g.query(m-j+1,m))
//				move(ans,1);
//			if (h[0].iquery(i-j+1,i+(m-2*j))==g.query(1,m-j)&&h[1].query(i-j+1,i)==g.query(m-j+1,m))
//				move(ans,1);				
//		}
		if (s[0][i]==t[1])move(f[i][1][0],1);
		if (s[1][i]==t[1])move(f[i][1][1],1);
		for (int j=1;j<=m;j++){
			if (s[0][i+1]==t[j+1]){
				move(f[i+1][j+1][0],f[i][j][0]);
				if (s[1][i+1]==t[j+2])
					move(f[i+1][j+2][1],f[i][j][0]);
			}
			if (s[1][i+1]==t[j+1]){
				move(f[i+1][j+1][1],f[i][j][1]);
				if (s[0][i+1]==t[j+2])
					move(f[i+1][j+2][0],f[i][j][1]);
			}
		}
		for (int j=2;j<m&&i+j<=n;j++){
			if (h[1].iquery(i+1,i+j)==g.query(m-j+1,m)&&h[0].query(i+1,i+j)==g.query(m-2*j+1,m-j))
				move(ans,f[i][m-2*j][0]);
			if (h[0].iquery(i+1,i+j)==g.query(m-j+1,m)&&h[1].query(i+1,i+j)==g.query(m-2*j+1,m-j))
				move(ans,f[i][m-2*j][1]);
		}
		move(ans,f[i][m][0]);
		move(ans,f[i][m][1]);
	}
	
}
int main(){
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	n=strlen(s[0]+1);
	scanf("%s",t+1);
	scanf("%s",t+1);
	m=strlen(t+1);
	if (m==1){
		for (int i=1;i<=n;i++)
			ans+=(t[1]==s[0][i])+(t[1]==s[1][i]);
		cout<<ans<<endl;
		return 0;
	}
	if (m==2){
		for (int i=1;i<=n;i++)
			ans+=(t[1]==s[0][i]&&t[2]==s[1][i])+(t[1]==s[1][i]&&t[2]==s[0][i]);
		for (int i=1;i<n;i++)
		for (int j=0;j<=1;j++)
			ans+=(t[1]==s[j][i]&&t[2]==s[j][i+1])+(t[1]==s[j][i+1]&&t[2]==s[j][i]);
		cout<<ans<<endl;
		return 0;
	}
	prep();
	dp();
	reverse(s[0]+1,s[0]+n+1);
	reverse(s[1]+1,s[1]+n+1);
	memset(f,0,sizeof f);
	dp();
	cout<<ans<<endl;
}