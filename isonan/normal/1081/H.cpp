#include <map>
#include <cstdio>
#include <cstring>
#define int long long

char s[200010],t[200010];
const int P1=1000000007,P2=998244353,v1=6667,v2=2333;
int Pow[2][200010];
struct pam{
	int cnt,last,fa[200010],len[200010],son[200010][26],nxt[200010],S[200010],n,end[200010];
	int pre[200010][21],pos[200010];
	int hash[2][200010];
	pam(){
		cnt=1;
		nxt[0]=1;
		len[1]=-1;
		S[n=0]=-1;
	}
	int getnxt(int x){
		while(S[n]!=S[n-len[x]-1])x=nxt[x];
		return x;
	}
	void add(int x){
		S[++n]=x;
		hash[0][n]=(1ll*hash[0][n-1]*v1+(x+1))%P1;
		hash[1][n]=(1ll*hash[1][n-1]*v2+(x+1))%P2;
		int cur=getnxt(last);
		if(!son[cur][x]){
			end[++cnt]=n;
			nxt[cnt]=son[getnxt(nxt[cur])][x];
			len[son[cur][x]=cnt]=len[cur]+2;
		}
		last=son[cur][x];
		pos[n]=last;
	}
	void set(){
		for(int i=0;i<=cnt;i++)pre[i][0]=nxt[i];
		for(int j=1;j<=20;j++)
			for(int i=0;i<=cnt;i++)
				pre[i][j]=pre[pre[i][j-1]][j-1];
	}
	std::pair<int,int>slice(int l,int r){
		return std::make_pair(
			(hash[0][r]+P1-(1ll*hash[0][l-1]*Pow[0][r-l+1]%P1))%P1,
			(hash[1][r]+P2-(1ll*hash[1][l-1]*Pow[1][r-l+1]%P2))%P2);
	}
	int palin(int l,int r){
		int tem=pos[r];
		for(int i=20;~i;--i){
//			printf("%d %d %d\n",tem,i,pre[tem][i]);
			if(pre[tem][i]>1&&len[pre[tem][i]]>r-l+1)tem=pre[tem][i];
		}
		if(len[tem]>r-l+1)tem=nxt[tem];
//		printf("&%d %d %d %d\n",l,r,len[tem],nxt[tem]);
		return len[tem];
	}
	int cut(int l,int r){
		int tem=palin(l,r);
		if(tem<r-l+1&&palin(l,r-tem)+tem==r-l+1)return tem;
		else return -1;
	}
}a,b;
long long ans;
std::map<std::pair<int,int>,int>ma,mb;
void getmap(pam&a,std::map<std::pair<int,int>,int>&map,int bb){
	for(int i=2;i<=a.cnt;i++)
		if(a.nxt[i]>1){
			if((bb==3&&(a.len[a.nxt[i]]<<1)>=a.len[i])||bb==0)++map[a.slice(a.end[i]-a.len[i]+a.len[a.nxt[i]]+1,a.end[i])];
//			printf("%d %d %d\n",a.len[i],a.len[a.nxt[i]],a.len[i]);
			else if((bb==4&&(a.len[a.nxt[i]]<<1)>=a.len[i])||bb==1)++map[a.slice(a.end[i]-a.len[i]+1,a.end[i]-a.len[a.nxt[i]])];
//			printf("%d %d %d\n",a.len[i],a.len[a.nxt[i]],a.len[i]);
		}
	for(int i=2;i<=a.cnt;i++)
		if(bb==2)++map[a.slice(a.end[i]-a.len[i]+1,a.end[i])];
//			printf("%d %d %d\n",a.len[i],a.len[a.nxt[i]],a.len[i]);
}
std::pair<int,int>merge(std::pair<int,int>a,std::pair<int,int>b,int x){
	return std::make_pair((1ll*a.first*Pow[0][x]+b.first)%P1,(1ll*a.second*Pow[1][x]+b.second)%P2);
}
void solve(pam &a,std::map<std::pair<int,int>,int>&map,bool bb){
	for(int i=2;i<=a.cnt;i++)
		if(a.nxt[i]>1)
			if(bb){
				int r=a.end[i],l=a.end[i]-a.len[i]+a.len[a.nxt[i]]+1,tem=a.cut(l,r);
				if(~tem&&map.count(a.slice(l,r-tem))&&map.count(merge(a.slice(l,r),a.slice(l,r-tem),r-l+1-tem)))--ans;
				else{
					l=a.end[i]-a.len[i]+1,r=a.end[i]-a.len[a.nxt[i]];
					tem=a.cut(l,r);
					if(~tem)tem=r-l+1-tem;
//					printf("%d %d %d\n",l,r,tem);
					r=a.end[i],l=a.end[i]-a.len[i]+a.len[a.nxt[i]]+1;
//					printf("%d\n",map.count(a.slice(l,r-tem)));
					if(~tem&&map.count(a.slice(l,r-tem))&&map.count(merge(a.slice(l,r),a.slice(l,r-tem),r-l+1-tem)))--ans;
				}
//				printf("*%d %d %d %d\n",ans,l,r,tem);
			}
			else{
				int l=a.end[i]-a.len[i]+1,r=a.end[i]-a.len[a.nxt[i]],tem=a.cut(l,r);
				if(~tem&&map.count(a.slice(r-tem+1,r))&&map.count(merge(a.slice(r-tem+1,r),a.slice(l,r),r-l+1)))--ans;
				else{
					r=a.end[i],l=a.end[i]-a.len[i]+a.len[a.nxt[i]]+1;
					tem=a.cut(l,r);
					if(~tem)tem=r-l+1-tem;
					l=a.end[i]-a.len[i]+1,r=a.end[i]-a.len[a.nxt[i]];
					if(~tem&&map.count(a.slice(r-tem+1,r))&&map.count(merge(a.slice(r-tem+1,r),a.slice(l,r),r-l+1)))--ans;
				}
//				printf("*%d %d %d %d\n",ans,l,r,tem);
			}
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%s%s",s+1,t+1);
	for(int i=1;s[i];i++)a.add(s[i]-'a');
	for(int i=1;t[i];i++)b.add(t[i]-'a');
	Pow[0][0]=Pow[1][0]=1;
	for(int i=1;i<=200000;i++)Pow[0][i]=1ll*Pow[0][i-1]*v1%P1;
	for(int i=1;i<=200000;i++)Pow[1][i]=1ll*Pow[1][i-1]*v2%P2;
	ans=1ll*(a.cnt-1)*(b.cnt-1);
	a.set();
	b.set();
	getmap(a,ma,2);
//	puts("");
	getmap(b,mb,2);
	solve(a,mb,1);
	solve(b,ma,0);
	ma.clear();
	mb.clear();
//	puts("");
	getmap(a,ma,0);
//	puts("");
	getmap(b,mb,4);
	for(auto it=ma.begin();it!=ma.end();++it)
		ans-=1ll*it->second*mb[it->first];
//	printf("%lld\n",ans);
	ma.clear();
	mb.clear();
	getmap(a,ma,3);
//	puts("");
	getmap(b,mb,1);
	for(auto it=ma.begin();it!=ma.end();++it)
		ans-=1ll*it->second*mb[it->first];
//		printf("%lld\n",ans);
	ma.clear();
	mb.clear();
	getmap(a,ma,0);
	getmap(b,mb,1);
	for(auto it=ma.begin();it!=ma.end();++it)
		ans+=1ll*it->second*mb[it->first];
	printf("%lld\n",ans);
}