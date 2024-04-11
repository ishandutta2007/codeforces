#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

int n, m = 100000, mv = -1, a, b, c;
vi v;

int main() {
	cin >> n;
	v.resize(n);
	for(auto& i : v)
		cin >> i;
	for(int t = 1; t < 105; t++) {
		a = 0;
		for(auto& i : v){
			if(i > t)
				a += (i - t - 1);
			else if(i < t)
				a += (t - i - 1);
		}
		if(a < m)
			m = a, mv = t;
	}
	cout << mv << " " << m;
}