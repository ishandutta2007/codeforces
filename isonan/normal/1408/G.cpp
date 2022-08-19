#include <cstdio>
#include <vector>
#include <bitset>
#include <random>
#include <algorithm>

int bb[1501];
const int P=998244353;
inline int add(int a,const int &b){
	a+=b;return(a>=P)?a-P:a;
}
inline int mul(const int &a,const int &b){
	return 1ll*a*b%P;
}
int f[4001][1501],n,size[1000001],cnt,last[1501],val[1501];
unsigned long long tem[1501];
int head[1000001],nxt[2000001],b[2000001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<std::pair<int,int> >a[1501];
bool vis[1000001];
void getans(int x,int F){
	vis[x]=1;
	size[x]=(size[x]==1);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F&&!vis[b[i]]){
			getans(b[i],x);
			size[x]+=size[b[i]];
			if(size[x]==size[b[i]]){
				for(int j=1;j<=size[b[i]];j++)f[x][j]=f[b[i]][j];
			}
			else{
				for(int j=1;j<=size[x];j++)tem[j]=0ll;
				unsigned long long p=1ll*P*P;
				for(int j=0;j<=size[b[i]];j++)
					for(int k=0;k<=size[x]-size[b[i]];k++){
						if((tem[j+k]+=1ll*f[b[i]][j]*f[x][k])>=p)tem[j+k]-=p;
					}
				for(int j=1;j<=size[x];j++)f[x][j]=tem[j]%P;
			}
		}
	f[x][1]=add(f[x][1],1);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	scanf("%d",&n);
	std::mt19937 rnd(19260817);
	for(int i=1;i<=n;i++)val[i]=rnd();
	for(int i=1;i<=n;i++)
		for(int j=1,tem;j<=n;j++){
			tem=read();
			if(i!=j)a[i].push_back(std::make_pair(tem,j));
		}
	for(int i=1;i<=n;i++){
		std::sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=n;i++)bb[i]=val[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bool cando=1;
			for(int k=1;k<i;k++)
				if(j>a[j][k-1].second)cando=0;
			for(int k=1;k<i;k++)
				if(bb[j]!=bb[a[j][k-1].second])cando=0;
			if(cando){
				++cnt;
				size[cnt]=i;
				for(int k=1;k<i;k++){
					if(last[a[j][k-1].second])push(cnt,last[a[j][k-1].second]);
					last[a[j][k-1].second]=cnt;
				}
					if(last[j])push(cnt,last[j]);
					last[j]=cnt;
			}
		}
		if(i<n)
			for(int j=1;j<=n;j++)bb[j]^=val[a[j][i-1].second];
	}
	getans(cnt,0);
	for(int i=1;i<=n;i++)write(f[cnt][i]),putchar(' ');
}