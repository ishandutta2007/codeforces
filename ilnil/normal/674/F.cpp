#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ui unsigned int
using namespace std;
const int N=132,M=1<<14;
int n,p,q;
ui f[M+5][N],g[N][N];
ui c[N][N],ans,tot;
struct ma{
	ui a[N][N];
	ma operator*(const ma &y)const{
		static ma z;
		memset(z.a,0,sizeof z.a);
		fo(i,0,p)fo(j,i,p)fo(k,j,p)z.a[i][k]+=a[i][j]*y.a[j][k];
		return z;
	}
}E,h[130];
int gcd(int x,int y){
	for(;y;y%=x)swap(x,y);
	return x;
}
ui C(int n,int m){
	if(m>n)return 0;
	vector<int>a;
	fo(i,0,m-1)a.push_back(n-i);
	fo(i,2,m){
		int b=i;
		fo(j,0,m-1){
			int gc=gcd(b,a[j]);
			b/=gc;a[j]/=gc;
			if(b==1)break;
		}
	}
	ui t=1;
	fo(i,0,m-1)t*=a[i];
	return t;
}
int main(){
	cin>>n>>p>>q;p=min(p,n-1);
	fo(i,0,p)c[0][i]=C(n-p,i);
	fo(i,1,p){
		c[i][0]=1;
		fo(j,1,p)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	fo(i,0,p)fo(j,i,p)E.a[i][j]=g[i][j]=c[j][j-i];
	for(int i=1;i<M;i<<=1)E=E*E;
	fo(i,0,p)h[0].a[i][i]=1;
	fo(i,1,q>>14)h[i]=h[i-1]*E;
	fo(i,0,p)f[0][i]=1;
	fo(i,1,min(M-1,q))
		fo(j,0,p)
			fo(k,j,p)
				f[i][k]+=f[i-1][j]*g[j][k];
	
	fo(i,1,q){
		int w1=i>>14,w0=i&(M-1);
		tot=0;
		fo(i,0,p)tot+=f[w0][i]*h[w1].a[i][p];
		ans^=tot*i;
	}
	cout<<ans;
}