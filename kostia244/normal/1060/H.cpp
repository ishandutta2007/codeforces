// Problem: H. Sophisticated Device
// Contest: Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1060/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int local = 0, zero = 4996;
int R[5050], d, p;
int pow(int x, int s) {
	int t = 1;
	for(int i = 0; i < s; i++)
		t = t*1ll*x%p;
	return t;
}
void op1(int i, int j, int k) {
	if(!local) cout << "+ " << i << " " << j << " " << k << endl;
	if(local) R[k] = (R[i]+R[j])%p;
}
void op2(int i,int k) {
	if(!local) cout << "^ " << i << " " << k << endl;
	if(local) {
		R[k] = pow(R[i], d);
	}
}
void _op3(int i, int j, int k) {//x != 1
	int init = 0;
	for(int bit = 1; bit < 30; bit++) {
		int f = bit == 1 ? j : 5000;
		if((p-1) & (1<<bit)) {
			if(!init) op1(f, f, k);
		}
		op1(f, f, 5000);
		if((p-1) & (1<<bit)) {
			if(init) op1(k, 5000, k);
			init = 1;
		}
	}
	op1(i, k, k);
}
void mul(int i, int x) {
	int z = R[i];
	op1(zero, i, 4995);
	op1(zero, zero, i);
	for(int bit = 0; bit < 30; bit++) {
		if(x & (1<<bit)) {
			op1(i, 4995, i);
		}
		op1(4995, 4995, 4995);
	}
	assert((z*1ll*x%p) == R[i]);
}
void op3(int i, int j, int k) {
	op1(j, zero, 4990);
	mul(4990, (p-1));
	op1(i, 4990, k);
}
using Poly = array<int, 11>;
int C[11][11];
Poly P[11], Q[11];
void sub(Poly &a, Poly b) {
	for(int i = 0; i <= d; i++)
		a[i] = (a[i]+p-b[i])%p;
}
int inv(int v) {
	return v > 1 ? p - (p/v)*1ll*inv(p%v)%p : v;
}
// 2 1000000007 2 5
void square(int from, int dest) {
	for(int i = 0; i <= d; i++)//P(1) ... P(d+1)
		for(int j = 0; j <= d; j++) {
			P[i][j] = C[d][j]*1ll*pow(i, d-j);
			Q[i][j] = i==j;
		}
	op1(from, zero, dest);
	for(int i = 1; i <= d; i++) {
		op1(dest-1+i, 4999, dest+i);
	}
	for(int i = 0; i <= d; i++)
		op2(dest+i, dest+i);
	// for(int i = 0; i <= d; i++)
		// cout << R[dest+i] << " "; cout << endl;
	for(int deg = d; deg > 2; deg--) {
		for(int i = 0; i < deg; i++) {
			sub(P[i], P[i+1]);
			sub(Q[i], Q[i+1]);
			// op3(dest+i, dest+i+1, dest+i);
			// cout << R[dest+i] << " ";
		}
		// cout << endl;
	}
	for(int i = 0; i <= d; i++) {
		mul(dest+i, Q[0][i]);
		if(i)
			op1(dest, dest+i, dest);
	}
	mul(dest+d+1, (p-P[0][0])%p);
	op1(dest, dest+d+1, dest);
	op1(from, zero, dest+d+2);
	mul(dest+d+2, (p-P[0][1])%p);
	op1(dest, dest+d+2, dest);
	mul(dest, inv(P[0][2]));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	for(int i = 0; i <= 10; i++)
		for(int j = 0; j <= i; j++)
			if(!j) C[i][j] = 1;
			else C[i][j] = C[i-1][j]+C[i-1][j-1];
	cin >> d >> p;
	if(local) {
		fill(R, R+5050, 1);
		cin >> R[1] >> R[2];
	}
	_op3(4998, 4997, zero);
	op1(1, 2, 3);
	square(1, 100);
	square(2, 200);
	square(3, 300);
	op3(300, 100, 300);
	op3(300, 200, 300);
	op1(300, zero, 3);
	mul(3, (p+1)/2);
	if(local)
	cout << R[3] << " vs " << R[1]*1ll*R[2]%p << endl;
	cout << "f " << 3 << endl;
}