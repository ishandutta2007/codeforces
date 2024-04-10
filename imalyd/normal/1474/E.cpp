#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
	int t;scanf("%d",&t);while(t--)ac();
	return 0;
}
inline ll sqr(const int &a){return (0ll+a)*a;}
inline void ac(){
	int n,m,i;ll t;
	scanf("%d",&n);
	if(n==1){printf("1\n1\n0\n");return;}
	if(n==2){printf("1\n2 1\n1\n2 1\n");return;}
	if(n==3){printf("5\n2 3 1\n2\n1 3\n3 2\n");return;}
	m=n>>1;
	t=sqr(n-1);
	REP(i,2,n)t+=sqr(max(i-1,n-i));
	printf("%lld\n",t);
	rep(i,1,n){
		if(i==1)printf("%d ",m+1);else
		if(i==m)printf("1 ");else
		if(i==n)printf("2 ");else
		printf("%d ",i+1);
	}
	printf("\n%d\n",n-1);
	rep(i,2,m)printf("%d %d\n",i,n);
	rep(i,m+1,n)printf("%d 1\n",i);
}