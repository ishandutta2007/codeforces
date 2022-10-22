#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const int inf=1e9;
const int P=998244353;
const int N=16050;
int n;
int LS[850],RS[850];
int lo,ro,cnt;
int s[850];
char str[850];
queue<int> Q;
int v[N][2005];
struct AC{
	int c[N][10],fail[N];
	void insert(int len,int mx){
		//for(int i=1;i<=len;++i) cout<<s[i];cout<<endl;
		int x=0;
		for(int i=1;i<=len;++i){
			if(!c[x][s[i]]) c[x][s[i]]=++cnt;
			x=c[x][s[i]];
		}
		++v[x][mx-len];
	}
	void build(){
		int x;
		for(int i=0;i<10;++i) if(c[0][i]) Q.push(c[0][i]);
		while(!Q.empty()){
			x=Q.front();Q.pop();
			//cout<<x<<endl;
			//if(x==11) cout<<"y"<<endl;
			for(int i=0;i<10;++i)
				if(c[x][i]){
					fail[c[x][i]]=c[fail[x]][i];
					for(int j=0;j<=ro;++j) v[c[x][i]][j]+=v[c[fail[x]][i]][j];
					Q.push(c[x][i]);
				}
				else{
					//if(x==11&&i==1) cout<<"y"<<endl;
					c[x][i]=c[fail[x]][i];
				}
		}
		for(int i=0;i<=cnt;++i){
			for(int j=1;j<=n;++j){
				v[i][j]+=v[i][j-1];
			}
		}
	}
}ac;
void dfs(int len,int fl,int fr,int mx,int op){
	if(fl&&fr){
		ac.insert(len,mx);
		return;
	}
	if(len==mx){
		ac.insert(len,mx);
		return;
	}
	if(mx<lo) return;
	if(mx>ro) return;
	if(mx>lo) fl|=1;
	if(mx<ro) fr|=1;
	for(int i=0;i<10;++i){
		if(len==0&&i==0) continue;
		if(fl==0&&i<LS[len+1]) continue;
		if(fr==0&&i>RS[len+1]) continue;
		s[len+1]=i;
		dfs(len+1,(i>LS[len+1]?1:0)|fl,(i<RS[len+1]?1:0)|fr,mx,op);
	}
}
int f[2050][N];
bool vis[2050][N];
int cal(int l,int r){
	if(l>r) return 0;
	return r-l+1;
}
void get(int i,int z){
	if(i==n) return;
	int x,y;
	for(int k=0;k<10;++k){
		y=f[i][z];
    	x=ac.c[z][k];
    	if(k) y+=cal(lo+1,min(ro-1,n-i));
    	y+=v[x][n-i-1];
    	if(y==f[i+1][x]&&vis[i+1][x]){
    		printf("%d",k);
    		get(i+1,x);
    		break;
		}
	}
}
int main(){
    scanf("%s",str+1);lo=strlen(str+1);
    for(int i=1;i<=lo;++i) LS[i]=str[i]-'0';
    scanf("%s",str+1);ro=strlen(str+1);
    for(int i=1;i<=ro;++i) RS[i]=str[i]-'0';
    scanf("%d",&n);
    if(lo==ro) dfs(0,0,0,lo,0);
    else{
    	dfs(0,0,0,lo,1);
    	dfs(0,0,0,ro,2);
	}
    ac.build();
    //cout<<cnt<<endl;
    //cout<<ac.c[11][1]<<" "<<ac.fail[11]<<" "<<ac.c[1][1]<<endl;
//    for(int i=0;i<=cnt;++i){
//    	cout<<ac.fail[i]<<endl;
//    	for(int j=0;j<=n;++j) cout<<v[i][j]<<" ";cout<<endl;
//	}
    int x,y;
    for(int i=0;i<=cnt;++i)for(int j=0;j<=n;++j) f[j][i]=-inf;
    f[0][0]=0;
    for(int i=0;i<n;++i){
    	for(int j=0;j<=cnt;++j){
    		if(f[i][j]<0) continue;
    		//cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
    		for(int k=0;k<10;++k){
    			y=f[i][j];
    			x=ac.c[j][k];
    			if(k) y+=cal(lo+1,min(ro-1,n-i));
    			y+=v[x][n-i-1];
    			f[i+1][x]=max(f[i+1][x],y);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=cnt;++i) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	for(int i=0;i<=cnt;++i) if(f[n][i]==ans) vis[n][i]=1;
	for(int i=n-1;i>0;--i){
		for(int j=0;j<=cnt;++j){
    		if(f[i][j]<0) continue;
    		//cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
    		for(int k=0;k<10;++k){
    			y=f[i][j];
    			x=ac.c[j][k];
    			if(k) y+=cal(lo+1,min(ro-1,n-i));
    			y+=v[x][n-i-1];
    			if(y==f[i+1][x]) vis[i][j]|=vis[i+1][x];
			}
		}
	}
	get(0,0);
	return 0;
}
/*
5
1 2 2
1 2 2
*/