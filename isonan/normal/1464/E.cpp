#include <cstdio>
#include <cstring>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,m,head[100001],nxt[200010],b[200010],k=1,d[100001],q[100001],h,t;
int cnt[100001],f[100001];
int map[701][710];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u];
	for(int i=1;i<=n;i++)if(!d[i])q[++t]=i;
	while(h<t){
		++h;
		memset(cnt,0,(700)<<2);
		for(int i=head[q[h]];i;i=nxt[i])
			if(i&1){
				if(!(--d[b[i]]))q[++t]=b[i];
			}
			else{
				cnt[f[b[i]]]=1;
			}
		for(f[q[h]]=0;cnt[f[q[h]]];++f[q[h]]);
	}
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)++cnt[f[i]];
	int inv=qsm(n+1,P-2);
	map[0][700]=sub(0,inv);
	for(int i=0;i<700;i++){
		for(int j=0;j<700;j++)
			map[i][j]=mul(cnt[i^j],inv);
		map[i][i]=sub(map[i][i],1);
	}
//	printf("%d %d\n",map[0][0],map[0][400]);
	for(int i=0;i<700;i++){
		for(int j=i;j<700;j++)
			if(map[j][i]){
				std::swap(map[i],map[j]);
				break;
			} 
		for(int j=i+1;j<700;j++)
			if(map[j][i]){
				int v=mul(qsm(map[i][i],P-2),map[j][i]);
				for(int k=0;k<=700;k++)
					map[j][k]=sub(map[j][k],mul(map[i][k],v));
			}
	}
	for(int i=699;~i;--i)
		for(int j=i-1;~j;--j)
			if(map[j][i]){
				int v=mul(qsm(map[i][i],P-2),map[j][i]);
				for(int k=0;k<=700;k++)
					map[j][k]=sub(map[j][k],mul(map[i][k],v));
			}
	printf("%d\n",sub(1,mul(map[0][700],qsm(map[0][0],P-2))));
}