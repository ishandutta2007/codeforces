#include<bits/stdc++.h>
using namespace std;
#define B 405
#define N 1000005
char buf[100000],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
int ee[N],c[N],s[N],n,m,x[N],y[N],i;
int gg[405][405];
int cal(int x){
	int res=0;
	for(int i=2;i<B;++i)res+=gg[i][(x-1)%i+1];return res;
}
int op,k,zz,j;
int main(){

	ios::sync_with_stdio(0);
	n=read();m=read();
	for(i=1;i<=n;++i)x[i]=read(),y[i]=read();
	for(i=1;i<=m;++i){
		op=read();k=read();
		if(op==1){
			ee[k]=i;
			zz=x[k]+y[k];
			if(x[k]+y[k]<=B)for(j=zz-2;j>=x[k]-1;--j)++gg[zz][(i+j)%zz+1];
			else{
				for(j=i+x[k];j<=m;j+=x[k]){
					++c[j];
					j+=y[k];
					if(j<=m)--c[j];
				}
			}
		}
		else{
			zz=x[k]+y[k];
			if(zz<=B)for(j=zz-2;j>=x[k]-1;--j)--gg[zz][(ee[k]+j)%zz+1];
			else{
				if((i-ee[k])%(x[k]+y[k])+1>x[k])--c[i];
				for(j=ee[k]+x[k];j<=m;j+=x[k]){
					if(j>i)--c[j];j+=y[k];
					if(j>i&&j<=m)++c[j];
				}
			}
		}
		s[i]=s[i-1]+c[i];
		cout<<s[i]+cal(i)<<'\n';
	}
}