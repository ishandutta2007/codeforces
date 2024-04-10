#include<cstdio>
#include<queue>
#define MAX   200200
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
int n,k;
ll a[MAX];
ll s[MAX];
ii m[MAX];
int f,l;
ll best;
void init(void) {
	int i;
	scanf("%d",&n);
	scanf("%d",&k);
	for (i=1;i<=n;i=i+1) scanf("%I64d",&a[i]);
	s[1]=0;
	for (i=1;i<=k;i=i+1) s[1]+=a[i];
	for (i=2;i+k-1<=n;i=i+1) s[i]=s[i-1]+a[i+k-1]-a[i-1];
	m[n-k+1]=ii(s[n-k+1],n-k+1);
	for (i=n-k;i>=1;i=i-1) {
		if (s[i]>=m[i+1].first) m[i]=ii(s[i],i);
		else m[i]=m[i+1];
	}		
	best=-1;
}
void count(void) {
	int i;
	for (i=1;i+2*k-1<=n;i=i+1)
		if (s[i]+m[i+k].first>best) {
			best=s[i]+m[i+k].first;
			f=i;
			l=m[i+k].second;
		}
	printf("%d %d",f,l);
}
int main(void) {
	init();
	count();
	return 0;
}