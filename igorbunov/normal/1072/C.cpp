#include <bits/stdc++.h>
#define for1(a,b,i) for(int i=a;i<=b;++i)
#define FOR2(a,b,i) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
inline int read() {
	int f=1,sum=0;
	char x=getchar();
	for(;(x<'0'||x>'9');x=getchar()) if(x=='-') f=-1;
	for(;x>='0'&&x<='9';x=getchar()) sum=sum*10+x-'0';
	return f*sum;
}
 
#define M 100005
int n,m;
 
vector <int> p,q;
 
inline bool check(int x) {return 1ll*x*(1+x)/2<=n+m;}
 
int main () {
	//freopen("a.in","r",stdin);
	n=read(),m=read();
	int l=1,r=1e5,mid,ans=0;
	while (l<=r) {
		mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	
	FOR2(ans,1,i) 
		if(n>=i) n-=i,q.push_back(i);
		else m-=i,p.push_back(i);
	int size=q.size();
	printf("%d\n",size);
	for1(1,size,i) printf("%d ",q[i-1]);
	puts("");
	size=p.size();
	printf("%d\n",size);
	for1(1,size,i) printf("%d ",p[i-1]);
	puts("");
}