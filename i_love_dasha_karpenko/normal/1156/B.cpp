#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
struct pp { ll a, b; };

ll t;
string s,news;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 0; h < t; h++) {
		cin >> s;
		string s1="", s2="",res1,res2;
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] - 'a') % 2 == 0)s1 += s[i];
			else s2 += s[i];
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		res1 = s1 + s2;
		res2 = s2 + s1;
		ll flag = 0;
		for (int i = 1; i < s.length(); i++) {
			if (abs(res1[i] - res1[i - 1]) == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << res1 << endl;
			continue;
		}
		flag = 0;
		for (int i = 1; i < s.length(); i++) {
			if (abs(res2[i] - res2[i - 1]) == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << res2 << endl;
			continue;
		}
		cout << "No answer" << endl;
	}
}