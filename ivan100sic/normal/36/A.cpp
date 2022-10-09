#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	#ifdef LOCAL
		auto& input = cin;
		auto& output = cout;
	#else
		ifstream input("input.txt");
		ofstream output("output.txt");
	#endif
	
	int n;
	input >> n;
	string s;
	input >> s;
	basic_string<int> a;
	for (int i=0; i<n; i++)
		if (s[i] == '1')
			a += i;
	for (int i=2; i<(int)a.size(); i++)
		if (a[i] - a[i-1] != a[1] - a[0])
			return output << "NO\n", 0;
	output << "YES\n";
}