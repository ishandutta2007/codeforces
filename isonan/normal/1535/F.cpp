#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <map>
#include <unordered_map>

const int P[2]={100000007,998244353};
int Pow[2][200001];
int n,L;
struct hash{
	int h[2];
	hash(int h0=0,int h1=0){h[0]=h0,h[1]=h1;}
	hash add(int x,int l=1){return (hash){(1ll*h[0]*Pow[0][l]+x)%P[0],(1ll*h[1]*Pow[1][l]+x)%P[1]};}
	operator long long(){return 1ll*h[0]*P[1]+1ll*h[1];}
};
long long c0,c1,c1337;
std::unordered_map<long long,int>map;
std::vector<hash>ft[200001],bk[200001];
std::vector<int>srt[200001];
hash v[200001];
char str[200001],s[200001];
int ord[200001],tem[200001],top;
int ind(int i,int j){
	return (i-1)*L+j;
}
int son[200010][26],cnt;
std::vector<int>node[200010];
int val[200001],tag[200001],now;
int& getv(int x){
	if(tag[x]<now)tag[x]=now,val[x]=0;
	return val[x];
}
int main(){
	// int st=clock();
	for(int i=0;i<2;++i){
		Pow[i][0]=1;
		for(int j=1;j<=200000;++j)Pow[i][j]=1ll*Pow[i][j-1]*132457689%P[i];
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		L=strlen(str+1);
		for(int j=1;j<=L;++j)s[ind(i,j)]=str[j];
		ft[i].resize(L+2);
		bk[i].resize(L+2);
		for(int j=1;j<=L;++j)ft[i][j]=ft[i][j-1].add(str[j]);
		for(int j=L;j>=1;--j)bk[i][j]=bk[i][j+1].add(str[j]);
		srt[i].resize(L+1);
		for(int j=L;j>=1;--j){
			srt[i][j]=(j<L&&s[ind(i,j)]<=s[ind(i,j+1)])?srt[i][j+1]:j;
		}
		node[i].resize(L+2);
		for(int j=L,now=0;j>=1;--j){
			if(!son[now][str[j]-'a'])son[now][str[j]-'a']=++cnt;
			now=son[now][str[j]-'a'];
			node[i][j]=now;
		}
		std::sort(str+1,str+L+1);
		for(int j=1;j<=L;++j)v[i]=v[i].add(str[j]);
	}
	map.clear();
	for(int i=1;i<=n;++i)c0+=map[ft[i][L]],++map[ft[i][L]];
	map.clear();
	c1337=(1ll*n*(n-1))/2ll;
	for(int i=1;i<=n;++i)c1337-=map[v[i]],++map[v[i]];
	bool bb;
	if(1ll*L*L<=200000)bb=1;
	else bb=0;
	if(!bb){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(ft[i][L]!=ft[j][L]&&v[i]==v[j]){
					bool ans=0;
					for(int k=1;k<=L;++k)
						if(ft[i][k-1]==ft[j][k-1]&&(bk[i][srt[i][k]+1]==bk[j][srt[i][k]+1]||bk[i][srt[j][k]+1]==bk[j][srt[j][k]+1]))ans=1;
					if(ans)++c1;
				}
	}
	else{
		for(int i=1;i<=n;++i)ord[i]=i;
		std::sort(ord+1,ord+n+1,[&](int a,int b){return v[a]<v[b];});
		for(int i=1,last=1;i<=n;++i)
			if(i==n||v[ord[i]]!=v[ord[i+1]]){
				for(int l=1;l<=L;++l){
					top=0;
					for(int j=last;j<=i;++j)tem[++top]=ord[j];
					std::sort(tem+1,tem+top+1,[&](int a,int b){return ft[a][l-1]<ft[b][l-1];});
					for(int j=1,last=1;j<=top;++j){
						if(j==top||ft[tem[j]][l-1]!=ft[tem[j+1]][l-1]){
							++now;
							for(int k=last;k<=j;++k)
								for(int m=l;m<=L;++m)
									++getv(node[tem[k]][m+1]);
							for(int k=last;k<=j;++k)
								if(l==1||s[ind(tem[k],l-1)]>s[ind(tem[k],l)]){
									c1+=getv(node[tem[k]][srt[tem[k]][l]+1]);
								}
							last=j+1;
						}
					}
				}
				last=i+1;
			}
		map.clear();
		for(int i=1;i<=n;++i){
			int cnt=0;
			for(int j=1;j<=L;++j)
				if(j==1||s[ind(i,j-1)]>s[ind(i,j)])
					++cnt;
			map[ft[i][L]]+=cnt;
		}
		for(int i=1;i<=n;++i){
			c1-=map[ft[i][L]];
		}
	}
	printf("%lld\n",c1337*1337ll+c1*1ll+(((1ll*n*(n-1))/2ll)-c1-c1337-c0)*2ll);
	// printf("used time: %d\n",clock()-st);
}