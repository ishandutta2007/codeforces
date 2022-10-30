#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[1000500],res,pre[2005000],lst[1005000],f[2000500][2],it;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main(){
	n=read();
	for(i=1;i<=n;i++){
		a[i]=read();
		pre[i]=(pre[i-1]^a[i]);
	}
	for(i=1;i<=20;i++){
		for(j=n;j>=1;j--){
			if(!(a[j]&b(i)))lst[j]=0;
			else lst[j]=(!lst[j+1])?j:lst[j+1];
		}
		it=0;
		for(j=1;j<=n;j++){
			f[pre[j]][(1&j)&1]=j;
			while(it<=n&&lst[it]<=j){
				if(lst[it]){
					res=max(res,f[pre[it-1]][(it&1)^1]-it+1);
				}
				it++;
			}
		}
		for(j=1;j<=n;j++)pre[j]>>=1;
		memset(f,0,4*b(21-i));
	}
	if(res==1)res=0;
	printf("%d",res);
}