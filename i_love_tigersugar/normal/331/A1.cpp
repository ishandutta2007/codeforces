#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX   100100
#define fs   first
#define sc   second
using namespace std;
typedef long long ll;
const ll INF=(ll)1e14+7;
typedef long long ll;
typedef pair<ll,int> ii;
vector<int> res,f,l;
vector<ll> v;
ll a[MAX];
ll s[MAX];
ii b[MAX];
int n;
ll best;
int bf,bl;
void init(void) {
	int i;
	scanf("%d",&n);
	s[0]=0;
	for (i=1;i<=n;i=i+1) {
		scanf("%I64d",&a[i]);
		if (a[i]>0) s[i]=s[i-1]+a[i];
		else s[i]=s[i-1];
		b[i]=ii(a[i],i);
	}
	sort(&b[1],&b[n+1]);
	b[0]=ii(-INF,-1);
	best=-INF;		
	v.clear();f.clear();l.clear();
	for (i=1;i<=n;i=i+1)
		if (b[i].fs>b[i-1].fs) {
			v.push_back(b[i].fs);
			f.push_back(b[i].sc);
			if (i>1) l.push_back(b[i-1].sc);
		}
	l.push_back(b[n].sc);
}
void count(void) {
	int i;
	for (i=0;i<v.size();i=i+1)
		if (l[i]!=f[i]) {
			if (best<a[f[i]]+a[l[i]]+s[l[i]-1]-s[f[i]]) {
				best=a[f[i]]+a[l[i]]+s[l[i]-1]-s[f[i]];
				bf=f[i];
				bl=l[i];
			}
		}
}
void print(void) {
	res.clear();
	int i;
	for (i=1;i<bf;i=i+1) res.push_back(i);
	for (i=bf+1;i<bl;i=i+1)
		if (a[i]<=0) res.push_back(i);
	for (i=bl+1;i<=n;i=i+1) res.push_back(i);
	printf("%I64d %d\n",best,res.size());
	if (res.size()==0) return;
	for (i=0;i<res.size()-1;i=i+1) printf("%d ",res[i]);
	printf("%d",res[res.size()-1]);
}
int main(void) {
	init();
	count();
	print();
	return 0;
}