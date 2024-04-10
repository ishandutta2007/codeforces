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
int n,m;
char s[N],t[N];
int a[N];
int main(){
	for(ri tt=read();tt;--tt){
		scanf("%s",s+1),n=strlen(s+1);
		scanf("%s",t+1),m=strlen(t+1);
		reverse(s+1,s+n+1),reverse(t+1,t+m+1);
		int pos=0;
		for(ri i=1;i<=m;++i)if(t[i]=='1'){pos=i;break;}
		bool f=1;
		if(!pos){cout<<"0\n";continue;}
		for(ri i=pos;i<=n;++i){
			if(s[i]=='1'){
				cout<<i-pos<<'\n';
				f=0;
				break;
			}
		}
		if(f)cout<<"0\n";
	}
	return 0;
}