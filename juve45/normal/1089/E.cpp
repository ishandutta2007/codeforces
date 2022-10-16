#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

// const int N = ;
int n, k, m;

int main() {
	ios_base::sync_with_stdio(false);
	string movs[] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
									 "b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1",
									 "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8",
									 "d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1",
									 "e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8",
									 "f8", "f7", "f6", "f5", "f4", "f3", "f2", "f1",

									 "g1", "g8", "g2", "g3", "g4", "g5", "g6", "g7",
									 "h7", "h6", "h5", "h4", "h3", "h2", "h1"};

	cin >> n; n--;

	if(movs[n - 1] == "g8") {
		for(int i = 0; i < n - 1; i++)
			cout << movs[i] << ' ';
		cout << "h1 h2 h8\n";
		return 0;
	}

	for(int i = 0; i < n; i++)
		cout << movs[i] << ' ';

	if(movs[n - 1][1] == '8'){
		cout << "g8 h8\n";
	}
	else if(movs[n][0] == 'h') {
		cout << movs[n] << " h8\n"; 
	} else {
		cout << 'h' << movs[n - 1][1] << " h8\n";
	}
	return 0;
}