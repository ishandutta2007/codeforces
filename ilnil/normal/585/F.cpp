#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2005,mo=1e9+7;
int n,tt,la,v,nv,no,m,s[N][10],nx[N][10],nx2[N][10],pr[N],d[N],t[N],w[N];
int f[2][2][N][27];
char c[N],a[100],b[100];
#define nw(x)(d[++tt]=d[x]+1,tt)
void add(int x){
	for(no=nw(la);!s[la][x];la=pr[la])s[la][x]=no;
	if(d[v=s[la][x]]==d[la]+1)pr[no]=v;else{
		nv=nw(la);pr[nv]=pr[v];pr[v]=pr[no]=nv;
		fo(i,0,9)s[nv][i]=s[v][i];
		for(;s[la][x]==v;la=pr[la])s[la][x]=nv;
	}la=no;
}
void dec(char *b){
	int n=strlen(b+1);
	for(;b[n]-=1,b[n]=='0'-1;--n)b[n]='9';
}
void _add(int o,int u,int j,int len,int k,int v){
	if(j){
		if(s[j][k])j=s[j][k],++len;
		else len=nx2[j][k],j=nx[j][k];
		if(len>m)j=len=0;
	}
	(f[o][u][j][len]+=v)%=mo;
}
int work(char *a){
	int len=strlen(a+1),o=0,v;
	fo(i,1,len)a[i]-='0';
	memset(f,0,sizeof f);
	f[0][1][1][0]=1;
	fo(i,1,len){
		o^=1;
		memset(f[o],0,sizeof f[o]);
		fo(j,0,tt)fo(le,0,m){
			if(v=f[!o][0][j][le])
				fo(k,0,9)_add(o,0,j,le,k,v);
			if(v=f[!o][1][j][le]){
				fo(k,0,a[i]-1)_add(o,0,j,le,k,v);
				_add(o,1,j,le,a[i],v);
			}
		}
	}
	int ans=0;
	fo(i,0,m)ans=((ll)ans+f[o][0][0][i]+f[o][1][0][i])%mo;
	return ans;
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	la=tt=1;d[0]=-1;
	fo(i,0,9)s[0][i]=1;
	fo(i,1,n)add(c[i]-='0');
	fo(i,1,tt)++t[d[i]];
	fo(i,1,n)t[i]+=t[i-1];
	fd(i,1,tt)w[t[d[i]]--]=i;
	scanf("\n%s\n%s",a+1,b+1);
	m=(strlen(a+1)>>1)-1;
	dec(a);
	fo(i,0,tt){
		int x=w[i];
		fo(j,0,9)if(s[x][j]){
			nx[x][j]=s[x][j];
			nx2[x][j]=d[x]+1;
		}else{
			nx[x][j]=nx[pr[x]][j];
			nx2[x][j]=nx2[pr[x]][j];
		}
	}
	cout<<(work(b)-work(a)+mo)%mo;
}