#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
class BIT {
	private:
	vector<int> v;
	int n;
	int get(int x) const {
		int ret=0;
		for (x;x>=1;x=x&(x-1)) ret+=v[x];
		return (ret);
	}	
	public:
	BIT() {
		n=0;		
	}
	BIT(int _n) {
		n=_n;
		v=vector<int>(n+7,0);
	}
	void update(int x) {
		for (x;x<=n;x+=x&(-x)) v[x]++;	
	}
	int sum(int l,int r) {
		return (get(r)-get(l-1));
	}
};
BIT bit;
int n,m;
int id[MAX];
bool chs[MAX];
set<int> notera;
void process(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	bit=BIT(n);
	FOR(i,1,n) {
		int t;
		scanf("%d",&t);
		id[t]=i;		
	}
	FOR(i,1,m) {
		int t;
		scanf("%d",&t);
		chs[t]=true;
	}
	long long res=0LL;
	notera.insert(0);
	notera.insert(n+1);
	FOR(i,1,n) {
		int p=id[i];
		if (chs[i]) notera.insert(p);
		else {
			set<int>::iterator it=notera.lower_bound(p);
			int r=(*it)-1;
			it--;
			int l=(*it)+1;
			res+=r-l+1-bit.sum(l,r);
			bit.update(p);
		}
	}
	cout << res;
}
int main(void) {
	process();
	return 0;
}