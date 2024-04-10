#include <iostream>
#include <vector>
using namespace std;

vector<int> v, sv;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		v.clear(); sv.clear();
		v.push_back(0);
		for (int i = 1; i <= n; i++) {
			int t = n / i;
			if (t < i) break;
			if (n / t != i) continue;
			v.push_back(i); 
			if (i != t) sv.push_back(t);
		}
		for (int i = (int)sv.size() - 1; i >= 0; i--)
			v.push_back(sv[i]);
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << '\n';
	}
	return 0;
}