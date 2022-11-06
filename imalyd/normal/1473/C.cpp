#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
const int MAXN=100005;
int A[MAXN];
inline void ac(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	rep(i,1,k)A[i]=i;
	reverse(A+(2*k-n),A+k+1);
	rep(i,1,k)printf("%d ",A[i]);printf("\n");
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)ac();
	return 0;
}