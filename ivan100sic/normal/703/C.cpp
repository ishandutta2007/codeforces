#include "bits/stdc++.h"
using namespace std;

struct pt {
	long long x, y;
	
	pt(long long x=0, long long y=0) : x(x), y(y) {}
};

struct rac {
	long long p, q;
	
	rac(long long p = 0, long long q=0) : p(p), q(q) {}
	
	bool operator< (const rac& o) const {
		return p * o.q < q * o.p;
	}
	
	bool operator<= (const rac& o) const {
		return p * o.q <= q * o.p;
	} 

	bool operator== (const rac& o) const {
		return p * o.q == q * o.p;
	}
	
	operator double () const {
		return p * 1.0 / q;
	}

};

ostream& operator << (ostream& os, const rac& br) {
	return os << setprecision(20) << ((double)br) << endl;
}

int N;
long long w, v, u;

rac proj(pt tac){
	// tac.x - tac.y / u * v;
	return rac(tac.x * u - tac.y * v, u);
}

pt A[10005];
rac P[10005], lp, hp, nula(0, 1); 

int main(){
	cin >> N >> w >> v >> u;
	for (int i=1; i<=N; i++){
		cin >> A[i].x >> A[i].y;
		P[i] = proj(A[i]);
		cerr << i << " " << P[i] << endl;
		if (i==1){
			hp = lp = P[i];
		} else {
			lp = min(lp, P[i]);
			hp = max(hp, P[i]);
		}
	}
	if (nula <= lp || hp <= nula){
		cout << rac(w, u);
	} else {
		cerr << hp << endl;
		cout << setprecision(20) << ((double)(hp / v) + (double)rac(w, u));
	}
	
	cin >> w;
	return 0;
}