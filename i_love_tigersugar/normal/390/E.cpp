#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
class BIT {
	private:
	int n;
	vector<ll> mul,add;
	void updatepoint(int x,ll m,ll a) {
		for (;x<=n;x+=x&(-x)) {
			mul[x]+=m;
			add[x]+=a;
		}		
	}
	ll getpoint(int x) {
		ll m=0LL;
		ll a=0LL;
		ll f=x;
		for (;x>=1;x=x&(x-1)) {
			m+=mul[x];
			a+=add[x];
		}
		return (m*f+a);
	}
	public:
	BIT() {
		n=0;
	}
	BIT(int n) {
		this->n=n;
		mul=vector<ll>(n+7,0LL);
		add=vector<ll>(n+7,0LL);
	}
	void update(int l,int r,ll x) {
		updatepoint(l,x,-x*(l-1));
		updatepoint(r,-x,x*r);
	}
	ll getsum(int l,int r) {
		return (getpoint(r)-getpoint(l-1));
	}
};
BIT row,col;
int m,n,q;
ll s;
void add(int x1,int y1,int x2,int y2,int v) {
	row.update(x1,x2,1LL*(y2-y1+1)*v);
	col.update(y1,y2,1LL*(x2-x1+1)*v);	
}
ll answer(int x1,int y1,int x2,int y2) {
	return (row.getsum(x1,x2)+col.getsum(y1,y2)-s);	
}
void process(void) {
	cin >> m >> n >> q;
	row=BIT(m);
	col=BIT(n);
	REP(i,q) {
		int t,x1,y1,x2,y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		if (t<1) {
			int v;
			cin >> v;
			add(x1,y1,x2,y2,v);
			s+=1LL*(x2-x1+1)*(y2-y1+1)*v;
		}
		else cout << answer(x1,y1,x2,y2) << "\n";
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	process();
	return 0;
}