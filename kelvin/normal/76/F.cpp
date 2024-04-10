#include <iostream>
#include <algorithm>
#define MAXN 100050

using namespace std;

class Coor {
	public:
		long long x,y;
		Coor() {}
		Coor(long long xi,long long yi):x(xi),y(yi) {}
		void input() { cin>>x>>y; }
		void print() { cout << x << " " << y << endl; }
		const bool operator<(const Coor &b) const {
			return x>b.x||x==b.x&&y>b.y;
		}
};

int n,slp;
Coor p[MAXN];

int ll;
long long lds[MAXN];

inline void tran() {
	int i;
	long long tx,ty;
	for(i=0;i<n;i++) {
		tx=p[i].x;
		ty=p[i].y;
		p[i].x=ty*slp+tx;
		p[i].y=ty*slp-tx;
	}
}

inline int findlds(Coor *p,int n) {
	int i,l,r,m;
	long long y;
	std::sort(p,p+n);
	ll=0;
	for(i=0;i<n;i++) {
		y=p[i].y;
		l=-1;
		r=ll;
		while(l<r-1) {
			m=(l+r)>>1;
			if(lds[m]<y) r=m;
			else l=m;
		}
		if(r==ll) ll++;
		lds[r]=y;
	}
	return ll;
}

inline void solve() {
	int i,sol1,sol2;
	tran();
	sol2=findlds(p,n);
//	p[n++]=Coor(0,0);
//	sol1=findlds(p,n)-1;
	while(n&&p[n-1].x<0) n--;
//	for(i=0;i<n;i++)
//		p[i].print();
	findlds(p,n);
	int l,r,m;
	long long y;
	y=0;
	l=-1;
	r=ll;
	while(l<r-1) {
		m=(l+r)>>1;
		if(lds[m]<y) r=m;
		else l=m;
	}
	sol1=r;
	cout << sol1 << " " << sol2 << endl;
}

int main(void)
{
	int i;
	while(cin>>n) {
		for(i=0;i<n;i++)
			p[i].input();
		cin>>slp;
		solve();
	}
}