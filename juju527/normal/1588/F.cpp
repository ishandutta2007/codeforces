//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,maxb=455;
ll a[maxn],s[maxn];
int p[maxn],buf[maxn],tmp[maxn];
struct que{int op,x,y;}Q[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool cut[maxn];
int f[maxn],id[maxn],F[maxn];
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
ll tag[4*maxb];
bool use[maxn];
int pos[maxn];
int num[4*maxb][2*maxb];
bool upd[maxn];
int main(){
    int n,q,B;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)buf[i]=read();
	q=read();B=sqrt(q);
	for(int i=1;i<=q;i++)Q[i].op=read(),Q[i].x=read(),Q[i].y=read();
	int lim=(q-1)/B+1;
	for(int c=1;c<=lim;c++){
		int l=(c-1)*B+1,r=min(c*B,q);
		for(int i=1;i<=n;i++)f[i]=i,tmp[i]=buf[i],id[i]=cut[i]=use[i]=upd[i]=0;
		for(int i=l;i<=r;i++){
			if(Q[i].op==1)continue;
			if(Q[i].op==2){upd[Q[i].x]=1;continue;}
			int x=Q[i].x,y=Q[i].y;
			cut[x]=cut[y]=cut[buf[x]]=cut[buf[y]]=1;
			upd[x]=upd[y]=upd[buf[x]]=upd[buf[y]]=1;
			swap(buf[x],buf[y]);
		}
		for(int i=1;i<=n;i++){
			if(cut[i])continue;
			if(find(i)==find(buf[i]))continue;
			upd[find(buf[i])]|=upd[find(i)];
			f[find(i)]=find(buf[i]);
		}
		int tot=0;
		for(int i=1;i<=n;i++)if(i==find(i)&&upd[i])id[i]=++tot;
		for(int i=1;i<=tot;i++)tag[i]=0;
		for(int i=1;i<=n;i++)F[i]=id[find(i)];
		for(int i=1;i<=n;i++)f[i]=F[i];
		for(int i=1;i<=tot;i++)p[i]=i;
		for(int i=1;i<=n;i++)if(cut[i])p[f[i]]=f[tmp[i]];
		for(int i=l;i<=r;i++){
			if(Q[i].op!=1)continue;
			int l=Q[i].x,r=Q[i].y;
			use[l-1]=1,use[r]=1;
		}
		int len=0;
		for(int i=0;i<=n;i++){
			if(i)num[f[i]][len+1]++;
			if(use[i])pos[i]=++len;
		}
		for(int i=1;i<=tot;i++)for(int j=1;j<=len;j++)num[i][j]+=num[i][j-1];
		for(int i=l;i<=r;i++){
			int op=Q[i].op,x=Q[i].x,y=Q[i].y;
			if(op==1){
				ll res=s[y]-s[x-1];
				for(int b=1;b<=tot;b++)
					res+=tag[b]*(num[b][pos[y]]-num[b][pos[x-1]]);
				printf("%lld\n",res);
			}
			else if(op==2){
				x=f[x];
				int z=x;tag[z]+=y;x=p[x];
				while(x^z)tag[x]+=y,x=p[x];
			}
			else{
				swap(p[f[x]],p[f[y]]);
			}
		}
		for(int i=1;i<=tot;i++)for(int j=1;j<=len+1;j++)num[i][j]=0;
		for(int i=1;i<=n;i++)a[i]+=tag[f[i]],s[i]=s[i-1]+a[i];
	}
    return 0;
}