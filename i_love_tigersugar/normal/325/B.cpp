#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
const ll LIM=2000000000;
set<ll> res;
ll n;
ll pw[77];
void init(void) {
	scanf("%I64d",&n);
	int i=1;
	pw[0]=1;
	pw[1]=2;
	while (pw[i]>pw[i-1]) {
		i=i+1;
		pw[i]=pw[i-1]*2;
	}
}
ll f(const int &k,const ll &x) {
	ll re=x*x+(pw[k+1]-3)*x;
	if (k>0 && re<=x*x) return (2*n+1);
	else return (re);
}
void test(const int &k) {
	ll l,m,r;	
	l=1;
	r=(2*n)/(pw[k+1]-3)+5;
	if (r>LIM || r<l) r=LIM;
	while (true) {
		if (r==l) {
			if (f(k,r)==2*n && r%2==1) {
				if (res.find(r)==res.end()) res.insert(r*pw[k]);
			}			
			return;
		}
		if (r-l==1) {
			if (f(k,r)==2*n && r%2==1) {
				if (res.find(r)==res.end()) res.insert(r*pw[k]);
			}
			if (f(k,l)==2*n && l%2==1) {
				if (res.find(l)==res.end()) res.insert(l*pw[k]);
			}
			return;
		}
		m=(l+r)/2;
		if (f(k,m)==2*n) {
			if (res.find(m)==res.end() && m%2==1) res.insert(m*pw[k]);
			return;
		}
		if (f(k,m)>2*n) r=m-1;
		else l=m+1;		
	}
}
void process(void) {
	int k;
	set<ll>::iterator it;
	res.clear();
	for (k=0;pw[k+1]-3<=2*n;k=k+1) test(k);
	if (res.empty()) printf("-1");
	else {
		for (it=res.begin();it!=res.end();it++) printf("%I64d\n",*it);
	}
}
int main(void) {
	init();
	process();
	return 0;
}