#include "bits/stdc++.h"
using namespace std;

long long triang(long long s){
	long long l = 0, r = 163500, m;
	while (l<=r){
		m = (l+r)/2;
		long long v = m*(m+1)/2;
		if (v < s){
			l = m+1;
		} else if (v > s){
			r = m-1;
		} else return m;
	}
	return -1;
}

void fail(){
	cout << "Impossible\n";
	exit(0);
}

long long a, b, c, d;

void specijal(){
	if (a+b+c == 0){
		if (triang(d) != -1){
			cout << string(triang(d)+1, '1');
			exit(0);
		}
	}
	if (b+c+d == 0){
		if (triang(a) != -1){
			cout << string(triang(a)+1, '0');
			exit(0);
		}
	}
}

string A;

int main(){
	
	long long bp, cp, nule, kecevi;
	
	cin >> a >> b >> c >> d;
	
	specijal();
	
	if (triang(a) == -1) fail();
	if (triang(d) == -1) fail();
	
	nule = triang(a) + 1;
	kecevi = triang(d) + 1;

	bp = nule * kecevi;
	cp = 0;
	
	if (b + c != bp) fail();
	
	A = string(nule, '0') + string(kecevi, '1');

	int lp = nule - 1, rp = nule + kecevi - 1;
	
	while (cp < c){
		if (rp - lp > c - cp){
			//cerr << c - cp << endl;
			rp = lp + c - cp;
			cp += rp - lp;
			swap(A[lp], A[rp]);
		} else if (rp - lp <= c - cp){
			//cerr << c - cp << endl;
			cp += rp-lp;
			swap(A[lp], A[rp]);
			rp--;
			lp--;
		}	
	}
	
	cout << A << '\n';
	
	cin >> a;
	
	return 0;
}