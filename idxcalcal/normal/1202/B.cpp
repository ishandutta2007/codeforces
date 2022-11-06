#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
	#undef gc
}
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){return (a+=b)>=mod?a-mod:a;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)>=mod?a-=mod:a;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e6+5;
int n,m,trans[10][10][10][10];
char s[N];
int a[N];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	memset(trans,-1,sizeof(trans));
	for(ri i=0;i<10;++i)for(ri j=0;j<10;++j)for(ri x=0;x<10;++x)for(ri y=0;y<10;++y)for(ri k=0;k<10;++k)for(ri l=0;l<10;++l){
		if(k+l&&(i+x*k+y*l)%10==j)if(~trans[i][j][x][y])trans[i][j][x][y]=min(trans[i][j][x][y],k+l);else trans[i][j][x][y]=k+l;
	}
	for(ri x=0;x<10;++x,puts(""))for(ri y=0;y<10;++y){
		bool f=1;
		int ans=0;
		for(ri i=2;i<=n;++i){
			if(trans[s[i-1]-'0'][s[i]-'0'][x][y]==-1){
				f=0;
				break;
			}
			ans+=trans[s[i-1]-'0'][s[i]-'0'][x][y]-1;
		}
		cout<<(f?ans:-1)<<' ';
	}
	return 0;
}