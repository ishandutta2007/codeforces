#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=3e5+5;
int n,m,x,y,z,js,la[N],ne[N*2],to[N*2],f[N],de[N],d[N];
int k,an[N],ans,gs;
bool b[N];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int main(){
//	freopen("a2.in","r",stdin);
	R(n);R(m);k=-1;
	fo(i,1,m)R(x),R(y),link(x,y),link(y,x);
	d[1]=1;b[1]=1;
	for(int t=0,w=1;t++<w;){
		int x=d[t];
		ff(x)if(!b[to[i]])
			b[to[i]]=1,d[++w]=to[i],f[to[i]]=x,de[to[i]]=de[x]+1;
	}
	if(de[n]){
		k=0;
		for(int i=n;i;i=f[i])an[++k]=i;
		fo(i,1,k>>1)swap(an[i],an[k-i+1]);
		k--;
	}
	if(k>4||k<0)
		fo(i,1,n)if(de[i]==2){
			if(k<0||k>4){
				an[1]=1;an[2]=f[i];an[3]=i;an[4]=1;an[5]=n;k=4;break;
			}
		}
		else ans+=(de[i]==1);
	fo(i,1,n)b[i]=0;
	if(k>5||k<0){
		fo(j,1,n)if(de[j]==1){
			b[j]=1;gs=1;
			ff(j)if(de[to[i]]==1)gs++,b[to[i]]=1;
			if(gs<ans){
				ff(j)if(de[to[i]]==1){
					int u=to[i];
					ff(u)if(de[to[i]]==1&&!b[to[i]]){
						an[1]=1;an[2]=j;an[3]=u;an[4]=to[i];an[5]=j;an[6]=n;k=5;
						break;
					}
				}
				if(k==5)break;
			}
			ff(j)if(de[to[i]]==1)b[to[i]]=0;
			b[j]=0;
		}
	}
	printf("%d\n",k);
	fo(i,1,k+1)printf("%d ",an[i]);
}