#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll; 
const int maxn=201000;
ll ans;
int n,p;
int a[maxn],ord[maxn],q[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
void proc(){
	n=read();p=read();
	for(register int i=1;i<=n;++i){
		a[i]=read();
		ord[i]=i;q[i]=0;
	}
	ans=1ll*p*(n-1);
	sort(ord+1,ord+1+n,cmp);
	for(register int i=1,l,r;i<=n;++i){
		if(a[ord[i]]>=p)break;
		l=r=ord[i];
		while(l>1){
			if(q[l])break;
			if(a[l-1]%a[ord[i]])break;
			--l;
		}
		while(r<n){
			if(q[r])break;
			if(a[r+1]%a[ord[i]])break;
			++r;
		}
		ans+=1ll*(r-l)*(a[ord[i]]-p);
		while(l<=r)++q[l],++l;
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)proc();
	return 0;
}