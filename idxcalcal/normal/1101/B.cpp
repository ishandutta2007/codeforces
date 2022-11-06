#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
const int N=105;
int mod,n,m,k;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
char s[500005];
int len;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s",s+1);
	len=strlen(s+1);
	int ps1=-1,ps2=-1,ps3=-1,ps4=-1;
	for(ri i=1;i<=len;++i){
		if(s[i]=='['&&ps1==-1){
			ps1=i;
		}
		if(s[i]==':'&&ps1!=-1){
			ps2=i;
			break;
		}
	}
	for(ri i=len;i;--i){
		if(s[i]==']'&&ps3==-1){
			ps3=i;
		}
		if(s[i]==':'&&ps3!=-1){
			ps4=i;
			break;
		}		
	}
	if(ps1==-1||ps2==-1||ps3==-1||ps4==-1||ps2>=ps4)return cout<<-1,0;
	int res=4;
	for(ri i=ps2+1;i<ps4;++i)if(s[i]=='|')++res;
	cout<<res;
	return 0;
}