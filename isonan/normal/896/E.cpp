#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#pragma GCC optimize(3)

const int N=500000;
const int block=(int)pow(N,0.5),s=N/block;
int n,m,a[N+10],pos[N+10],start[N+10];
int f[N+10],head[N+10],mx,cnt,g[N+10],v[N+10];
int op[N+10],l[N+10],r[N+10],x[N+10],ans[N+10];
inline int find(const int &x){return f[x]?f[x]=find(f[x]):x;}
int L,R;
void Delete(){
	for(register int i=L;i<=R;++i){
		a[i]=v[find(i)];
		g[head[a[i]]]=0;
		head[a[i]]=0;
	}
	for(register int i=L;i<=R;++i)f[i]=0;
}
void rebuild(){
	mx=0;
	for(register int i=L;i<=R;++i){
		if(!head[a[i]])v[head[a[i]]=i]=a[i];
		else f[i]=head[a[i]];
		++g[head[a[i]]];
		mx=std::max(mx,a[i]);
	}
}
void change(const int &i,const int &v,int *h1,int *h2){
	if(*h1){
		if(!*h2){
			*h2=*h1;
			::v[*h2]=v;
			*h1=0;
		}
		else{
			g[*h2]+=g[*h1];
			g[*h1]=0;
			f[*h1]=*h2;
			*h1=0;
		}
	}
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(const int &x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("Isomer.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	memset(start,-1,sizeof start);
	for(int i=1;i<=n;i++){
		pos[i]=(i-1)/block+1;
		if(!~start[pos[i]])start[pos[i]]=i-1;
	}
	for(int i=1;i<=m;i++)op[i]=read(),l[i]=read(),r[i]=read(),x[i]=read();
	for(register int i=1;i<=pos[n];++i){
		L=start[i]+1,R=(i==pos[n])?n:start[i+1];
		cnt=mx=0;
		rebuild();
		for(register int j=1,d,u,x,v;j<=m;++j){
			if(L>r[j]||R<l[j])continue;
			d=std::max(L,l[j]),u=std::min(R,r[j]),x=::x[j]+cnt,v=::x[j];
			if(d==L&&u==R){
				if(op[j]==1){
					if(mx-cnt-v>v){
						for(register int i=1+cnt,c=i+v,*h1=head+i,*h2=head+i+v;i<=v+cnt;++i,++c,++h1,++h2)change(i,c,h1,h2);
						cnt+=v;
					}
					else{
						for(register int i=v+1+cnt,c=i-v,*h1=head+i,*h2=head+i-v;i<=mx;++i,++c,++h1,++h2)change(i,c,h1,h2);
						mx=std::min(mx,cnt+v);
					}
				}
				else{
					if(x<=mx)ans[j]+=g[head[x]];
				}
			}
			else{
				if(op[j]==1){
					Delete();
					for(register int k=d;k<=u;++k)if(a[k]>x)a[k]-=v;
					rebuild();
				}
				else{
					for(register int k=d;k<=u;++k)ans[j]+=(::v[find(k)]==x);
				}
			}
		}
		Delete();
	}
	for(int i=1;i<=m;i++)if(op[i]==2)write(ans[i]),putchar('\n');
}