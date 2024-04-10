#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const ll INF=1e14;
int n,k,a[110000];
ll b[110]; int cnt;
map<ll,int> mp;
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=Getchar();
	return x*f;
}
inline ll myabs(ll x){ return x<0?-x:x;}
int main(){
	n=read(); k=read(); cnt=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (ll w=1;myabs(w)<=INF;w*=k){
		b[++cnt]=w;
		if (k==1||k==-1&&cnt==2) break;
	}
	mp.clear(); 
	mp[0]++; ll ans=0,s=0;
	for (int i=1;i<=n;i++){
		s+=a[i];
		for (int j=1;j<=cnt;j++) ans+=mp[s-b[j]];
		mp[s]++;
	}
	printf("%lld\n",ans);
	return 0;
}