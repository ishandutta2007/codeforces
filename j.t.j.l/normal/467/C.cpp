#include<iostream>
#include<cmath> 
#include<cstdio>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,i,j,k,m;
long long a[6000],s[6000],f[5100][5100],ans;


long long mmax(long long p,long long q){
	if (p>q) return p;
	else return q; 
}

long long mmin(long long p,long long q){
	if (p<q) return p;
	else return q; 
}

int main(){
	cin>>n>>m>>k;
	rep(i,1,n)
	  scanf("%d",&a[i]);
	s[m]=0;
	rep(i,1,m)
	   s[m]+=a[i];
	rep(i,m+1,n)
	   s[i]=s[i-1]+a[i]-a[i-m];	   
	rep(i,0,k)
	rep(j,0,m)
		f[i][j]=0;
	f[1][m]=s[m];
	rep(i,m+1,n){
		f[0][i]=0;
		rep(j,1,mmin(k,i/m))
			f[j][i]=mmax(f[j-1][i-m]+s[i],f[j][i-1]);
	}
	ans=0;
	rep(i,0,n)
		if (f[k][i]>ans){
			ans=f[k][i];
		} 
	cout<<ans<<endl;
	return 0;
}