#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, k, nr[1555], cnt = 1;
string ans;

int random(int black) {
	int x = rand()% n;
	x++;
	while(x == black)
		x = rand()% n + 1;
	return x;
}

bool inside(int a, int j, int i) {
	string ret;
	cout << "? " << a << ' ' << j << ' ' << i << endl;
	cin >> ret; 
	return (ret == "Yes");
}

vector <int> find_leafs() {
	for(int i = 1; i < 50; i++) {
		vector <int> v;
		int a = random(-1);
		int b = random(a);
		for(int i = 1; i <= n; i++) {
			if(i != a && i != b && inside(a, i, b))
				v.push_back(i);
		}
		if(v.size() == cnt + cnt - 3) {
			v.push_back(a);
			return v;
		}
	}
	exit(-1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	srand(6738);
	
	int lvl = 1, sum = 1;
	while(sum < n) {
		lvl *= k;
		sum += lvl;
		cnt++;
	}
	// dbg(sum, n);
	// dbg(cnt); // nr de niveluri

	vector <int> v = find_leafs();

	int a = v.back();
	// dbg(v);
	// v.pop_back();
	// int b = v.back();
	v.pop_back();

	for(auto i : v)  {
		int nr = 0;

		for(auto j : v) 
			if(i != j && inside(a, j, i))
				nr++;
		
		if(nr == cnt - 2)
			return cout << "! " << i << endl, 0;
	}

}