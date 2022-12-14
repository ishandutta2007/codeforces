#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

inline int che(int s, int t, int o)
{
	if(!s&&!t)return 0;
	if(s>t){
		for(int i=o;i>=0;--i)if(s>=1<<i){
			if(t>=1<<i)return che(s-(1<<i),t-(1<<i),i-1);
			return che(s-(1<<i),t,i-1)^1;
		}
	}
	for(int i=o;i>=0;--i)if(t>=1<<i){
		if(s>=1<<i)return che(s-(1<<i),t-(1<<i),i-1);
		return che(s,t-(1<<i),i-1)^1;  
	}
}

#define N 2097
long long ss,cc,dd;
int a[N][N],n,m,q,f1[N][N],f2[N][N],f3[N][N],f4[N][N],s,t,s_,t_,b,c,d,e,g,g_;

int main()
{
	n=read(); m=read(); q=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)a[i][j]=getchar()-48;
		getchar(); 
	} 
	for(int i=n+1;i<=n+n;++i)
	for(int j=1;j<=m;++j)a[i][j]=a[i-n][j]^1;
	for(int i=1;i<=n;++i)
	for(int j=m+1;j<=m+m;++j)a[i][j]=a[i][j-m]^1;
	for(int i=n+1;i<=n+n;++i)
	for(int j=m+1;j<=m+m;++j)a[i][j]=a[i-n][j-m];
	n<<=1; m<<=1;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)f1[i][j]=f1[i-1][j]+f1[i][j-1]-f1[i-1][j-1]+a[i][j]; //zs
	for(int i=1;i<=n;++i)
	for(int j=m;j;--j)f2[i][j]=f2[i-1][j]+f2[i][j+1]-f2[i-1][j+1]+a[i][j]; //ys
	for(int i=n;i;--i)
	for(int j=1;j<=m;++j)f3[i][j]=f3[i+1][j]+f3[i][j-1]-f3[i+1][j-1]+a[i][j]; //zx
	for(int i=n;i;--i)
	for(int j=m;j;--j)f4[i][j]=f4[i+1][j]+f4[i][j+1]-f4[i+1][j+1]+a[i][j]; //yx
	
	cc=n*m; dd=n*m/2;
	
	while(q--){
		ss=0;
		b=read(); c=read(); d=read(); e=read();
		s=(b-1)/n;	t=(c-1)/m;
		s_=(d-1)/n;  t_=(e-1)/m;
		if(s==s_){
			if(t==t_){
				g=che(s,t,29);         cerr<<g<<endl; 
				
				b=(b-1)%n+1;d=(d-1)%n+1;
				c=(c-1)%m+1;e=(e-1)%m+1;
				
//				cerr<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<endl;
//				cerr<<f1[0][1]<<endl;
				ss=f1[d][e]-f1[b-1][e]-f1[d][c-1]+f1[b-1][c-1];
				if(g)ss=(d-b+1)*(e-c+1)-ss;
				printf("%lld\n",ss);
				continue;
			}
			ss=(long long)(t_-t-1)*(d-b+1)*m/2;
			
			
			
			g=che(s,t,29); g_=che(s_,t_,29);
			b=(b-1)%n+1;d=(d-1)%n+1;
			c=(c-1)%m+1;e=(e-1)%m+1;
			if(!g){
				ss+=f1[d][m]-f1[b-1][m]-f1[d][c-1]+f1[b-1][c-1];
			} else {
				ss+=(m-c+1)*(d-b+1)-(f1[d][m]-f1[b-1][m]-f1[d][c-1]+f1[b-1][c-1]);
			}
			
			
			if(!g_){
				ss+=f2[d][1]-f2[b-1][1]-f2[d][e+1]+f2[b-1][e+1];
			} else {
				ss+=e*(d-b+1)-(f2[d][1]-f2[b-1][1]-f2[d][e+1]+f2[b-1][e+1]);
			}
			
			printf("%lld\n",ss);
			continue;  
		}
		if(t==t_){
			ss=(long long)(s_-s-1)*(e-c+1)*n/2;
			g=che(s,t,29); g_=che(s_,t_,29);
			b=(b-1)%n+1;d=(d-1)%n+1;
			c=(c-1)%m+1;e=(e-1)%m+1;
			if(!g){
				ss+=f1[n][e]-f1[n][c-1]-f1[b-1][e]+f1[b-1][c-1];
			} else ss+=(n-b+1)*(e-c+1)-(f1[n][e]-f1[n][c-1]-f1[b-1][e]+f1[b-1][c-1]);
			if(!g_){
				ss+=f1[d][e]-f1[d][c-1];
			}else ss+=d*(e-c+1)-(f1[d][e]-f1[d][c-1]);
			printf("%lld\n",ss);
			continue;
		}
		b=(b-1)%n+1;d=(d-1)%n+1;
		c=(c-1)%m+1;e=(e-1)%m+1;
		ss=(long long)(s_-s-1)*(t_-t-1)*dd;
		
//		cerr<<ss<<endl;
		
		ss+=(long long)(s_-s-1)*(m-c+1)*n/2;
		ss+=(long long)(s_-s-1)*e*n/2;
		ss+=(long long)(t_-t-1)*(n-b+1)*m/2;
		ss+=(long long)(t_-t-1)*d*m/2;
		
//		cerr<<ss<<endl;
		
		g=che(s,t,29);//cerr<<g<<endl; 
		if(!g)ss+=f4[b][c];else ss+=(n-b+1)*(m-c+1)-f4[b][c];
		
//		cerr<<ss<<endl;  
		
		g=che(s_,t,29);
		
		
		
		
		
//		cerr<<s_<<' '<<t<<endl;   
		
		
		
		if(!g)ss+=f2[d][c];else ss+=d*(m-c+1)-f2[d][c];
//		cerr<<ss<<endl;
		
		g=che(s,t_,29);//cerr<<g<<endl; 
		if(!g)ss+=f3[b][e];else ss+=(n-b+1)*e-f3[b][e];
		
//		cerr<<ss<<endl;
		
		g=che(s_,t_,29);//cerr<<g<<endl; 
		if(!g)ss+=f1[d][e];else ss+=d*e-f1[d][e];
		
//		cerr<<ss<<endl;
		
		printf("%lld\n",ss);
//		continue;
	}
}

/*
1 2 1
01
3 2 3 4
*/