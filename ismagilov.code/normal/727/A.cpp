#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	bool prav = 0;
	vector<int> put;
	int b1 = b;
	while (b > a){
		put.push_back(b);
		if (b % 2 == 0){
			b /= 2;
		}
		else{
			if (b % 10 == 1){
				b /= 10;
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
		if (b == a){
			put.pb(a);
			reverse(put.begin(), put.end());
			cout << "YES" << endl;
			cout << put.size() << endl;
			for (auto v : put){
				cout << v << ' ';
			}
			return 0;
		}
	}
	cout << "NO";
}