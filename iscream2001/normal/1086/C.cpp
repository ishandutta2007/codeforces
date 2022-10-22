#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB double
#define pa pair<LL,int>
#define ctz __builtin_ctz
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void Out(int x){
    if(x>9) Out(x/10);
    putchar(x%10+'0'); 
}

LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}
const int N=1e6+10;
char s[N],a[N],b[N];
int S[N],A[N],B[N];
int n,k;
int c[30];
bool vis[30];
int ansc[30];
bool dfs(int cs,bool aa,bool bb){
	if(cs>n) return 1;
	S[cs]=s[cs]-'a'+1;
	A[cs]=a[cs]-'a'+1;
	B[cs]=b[cs]-'a'+1;
	if(c[S[cs]]){
		S[cs]=c[S[cs]];
		if(S[cs]>A[cs]) aa=1;
		if(S[cs]<B[cs]) bb=1;
		if(aa&&bb) return 1;
		if(S[cs]<A[cs]&&aa==0) return 0;
		if(S[cs]>B[cs]&&bb==0) return 0;
		return dfs(cs+1,aa,bb); 
	}
	if(aa){
		for(int i=1;i<=k;++i){
			if(i>B[cs]) return 0;
			else if(vis[i]) continue;
			else {
				c[S[cs]]=i;
				vis[i]=1;
				break;
			}
		}
		if(c[S[cs]]<B[cs]) return 1;
		bool flag=dfs(cs+1,aa,bb);
		if(flag) return 1;
		else{
			vis[c[S[cs]]]=0;
			c[S[cs]]=0;
			return 0;
		}
	}
	if(bb){
		for(int i=k;i>=1;--i){
			if(i<A[cs]) return 0;
			else if(vis[i]) continue;
			else {
				c[S[cs]]=i;
				vis[i]=1;
				break;
			}
		}
		if(c[S[cs]]>A[cs]) return 1;
		bool flag=dfs(cs+1,aa,bb);
		if(flag) return 1;
		else{
			vis[c[S[cs]]]=0;
			c[S[cs]]=0;
			return 0;
		}
	}
	for(int i=A[cs]+1;i<B[cs];++i){
		if(!vis[i]){
			c[S[cs]]=i;
			vis[i]=1;
			return 1;
		}
	}
	bool flag;
	if(!vis[A[cs]]){
		c[S[cs]]=A[cs];
		vis[A[cs]]=1;
		if(A[cs]<B[cs]) bb=1;
		flag=dfs(cs+1,aa,bb);
		if(flag) return 1;
		else{
			vis[c[S[cs]]]=0;
			c[S[cs]]=0;
		}
	}
	aa=bb=0;
	if(!vis[B[cs]]){
		c[S[cs]]=B[cs];
		vis[B[cs]]=1;
		if(A[cs]<B[cs]) aa=1;
		flag=dfs(cs+1,aa,bb);
		if(flag) return 1;
		else{
			vis[c[S[cs]]]=0;
			c[S[cs]]=0;
		}
	}
	return 0;
}

int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int T;cin>>T;
    while(T--){
    	memset(c,0,sizeof(c));
    	memset(vis,0,sizeof(vis));
    	scanf("%d",&k);
    	scanf("%s%s%s",s+1,a+1,b+1);
    	n=strlen(s+1);
    	bool flag=dfs(1,0,0);
    	if(!flag) puts("NO");
    	else{
    		puts("YES");
    		for(int i=1;i<=k;++i){
    			if(c[i]) continue;
    			for(int j=1;j<=k;++j){
    				if(!vis[j]){
    					c[i]=j;
    					vis[j]=1;
    					break;
					}
				}
			}
			for(int i=1;i<=k;++i) printf("%c",(char)(c[i]+'a'-1));
			puts("");
		}
	}
	return 0;
}
/*






*/