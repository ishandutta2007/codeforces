#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x;
double l, v1, v2;
string s, op;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


/*

10 -> 10 nimic
10 -> 11 | 1
10 -> 00 & 0
10 -> 01 ^ 1
*/

int exec(int n, string op, int val) {
	if(op == "|") return n | val;
	if(op == "^") return n ^ val;
	if(op == "&") return n & val;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int x0 = 0, x1 = 1023;
	for(int i = 1; i <= n ;i++) {
		cin >> op >> x;
		x0 = exec(x0, op, x);
		x1 = exec(x1, op, x);
	}

	int xxor = 0;
	int aand = 1023;
	int oor = 0;

	for(int i = 0; i < 10; i++) {
		if(x1 & (1 << i) && !(x0 & (1 << i))) continue;
		if(!(x1 & (1 << i)) && (x0 & (1 << i))) { xxor += (1 << i);}
		if(!(x1 & (1 << i)) && !(x0 & (1 << i))) { aand -= (1 << i);}
		if((x1 & (1 << i)) && (x0 & (1 << i))) { oor += (1 << i);}
	}

	cout << "3\n";
	cout << "| " << oor << '\n';
	cout << "& " << aand << '\n';
	cout << "^ " << xxor << '\n';
}