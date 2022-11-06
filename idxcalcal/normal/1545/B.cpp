#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 100010
char s[Maxn];

const int Mod=998244353;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int fact[Maxn],inv[Maxn],ifac[Maxn];

void init(){
	fact[0]=1;rep(i,1,n)fact[i]=mul(fact[i-1],i);
	inv[0]=inv[1]=1;rep(i,2,n)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;rep(i,1,n)ifac[i]=mul(ifac[i-1],inv[i]);
}

int C(int a,int b){
	if(b<0||a<b)return 0;
	return mul(fact[a],mul(ifac[b],ifac[a-b]));
}

bool vis[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		init();
		int s1=0,s2=0;
		rep(i,1,n)vis[i]=0;
		rep(i,2,n)
			if(s[i-1]=='1'&&s[i]=='1'&&!vis[i-1]&&!vis[i]){
				vis[i-1]=vis[i]=1;
				s2++;
			}
		rep(i,1,n)
			if(s[i]=='1')s1++;
		s1=s1-s2*2;
		printf("%d\n",C(n-s1-s2,s2));
	}
	return 0;
}