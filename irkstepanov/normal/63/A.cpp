#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct datum {
	int type;
	int id;
	string name;
	bool operator<(const datum& other) const {
		if (type != other.type) {
			return type < other.type;
		}
		return id < other.id;
	}
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<datum> a(n);
    for (int i = 0; i < n; ++i) {
    	string name, type;
    	cin >> name >> type;
    	int t;
    	if (type == "rat") {
    		t = 0;
    	} else if (type == "child" || type == "woman") {
    		t = 1;
    	} else if (type == "man") {
    		t = 2;
    	} else {
    		t = 3;
    	}
    	a[i] = {t, i, name};
    }

    sort(all(a));

    for (int i = 0; i < n; ++i) {
    	cout << a[i].name << "\n";
    }

}