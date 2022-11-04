#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int a, b;
	cin >> a >> b;
	int mx = max(a, b);
	map<int, string> d = {{1, "1/1"}, {2, "5/6"}, {3, "2/3"}, {4, "1/2"}, {5, "1/3"}, {6, "1/6"}};
	cout << d[mx];
}