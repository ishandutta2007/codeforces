#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
//mt19937 rr(random_device{}());

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");
	
	int k;
	cin >> k;

	if (k == 0) {
		cout << "z\n";
		return 0;
	}

	int cnt = 0;
	while (k) {
		int s = 2;
		while ((s + 1) * s / 2 <= k) {
			++s;
		}
		for (int i = 0; i < s; ++i) {
			cout << char(cnt + 'a');
		}
		k -= s * (s - 1) / 2;
		++cnt;
	}

	cout << "\n";
		
}