#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const ll base = 1e17;
const int kmax = 40;

struct Number {
	ll m[kmax];
	Number() {
		memset(m, 0, sizeof(m));
	}
	Number(ll val) {
		memset(m, 0, sizeof(m));
		m[0] = val;
	}
	ll& operator[](int pos) {
		return m[pos];
	}
	bool operator<(const Number& other) const {
		for (int i = kmax - 1; i >= 0; --i) {
			if (m[i] != other.m[i]) {
				return m[i] < other.m[i];
			}
		}
		return false;
	}
	bool operator==(const Number& other) const {
		for (int i = 0; i < kmax; ++i) {
			if (m[i] != other.m[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const Number& other) const {
		return !(*this == other);
	}
};

Number operator-(Number& a, Number& b) {
	Number ans;
    int c = 0;
    for (int i = 0; i < kmax; ++i) {
        ans[i] = a[i] - b[i] + c;
        if (ans[i] < 0) {
            ans[i] += base;
            c = -1;
        } else {
            c = 0;
        }
    }
    return ans;
}

Number operator*(Number& a, int val) {
    ll c = 0;
    Number ans;
    for (int i = 0; i < kmax; ++i) {
        c += a[i] * val;
        ans[i] = c % base;
        c /= base;
    }
    return ans;
}

const int nmax = 610;

set<pair<Number, Number> > s[nmax];

void write(Number& a) {
	bool out = false;
	for (int i = kmax - 1; i >= 0; --i) {
		if (out) {
			printf("%017lld", a[i]);
		} else if (a[i]) {
			out = true;
			printf("%lld", a[i]);
		}
	}
}

Number convert(const string& s) {
	Number ans;
	int pos = 0;
	for (int i = sz(s) - 1; i >= 0; i -= 17) {
		ll val = 0;
		for (int j = max(i - 16, 0); j <= i; ++j) {
			val *= 10;
			val += s[j] - '0';
		}
		ans[pos++] = val;
	}
	return ans;
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    /*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/

	/*vector<int> a = {base - 1};
	vector<int> b = a * 12;
	cout << b[0] << " " << b[1] << "\n";*/

    s[2].insert({Number(13), Number(2)});
    for (int i = 3; i < nmax; ++i) {
        for (auto it : s[i - 1]) {
            pair<Number, Number> p;
            p.first = it.second * 12;
            p.second = it.first;
            s[i].insert(p);
			Number t = p.first;
            p.first = it.first * 13;
			p.first = p.first - t;
            s[i].insert(p);
        }
    }

    string str;
	cin >> str;
	if (str == "2") {
		cout << "YES\n1\n1\n0\n";
		return 0;
	}

	Number v = convert(str);
	vector<int> years;
	for (int i = 1; i < nmax; ++i) {
		for (auto it : s[i]) {
			if (it.first == v) {
				years.pb(i);
				break;
			}
		}
	}

	if (years.empty()) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << sz(years) << "\n";
	for (int x : years) {
		cout << x << "\n";
	}
	vector<Number> others;
	for (int x : years) {
		for (auto it : s[x]) {
			if (it.first != v) {
				others.pb(it.first);
			}
		}
	}
	sort(all(others));
	others.resize(unique(all(others)) - others.begin());
	int buben = 1000;
	cout << min(sz(others), buben) << "\n";
	for (int i = 0; i < min(sz(others), buben); ++i) {
		write(others[i]);
		cout << "\n";
	}
	/*for (auto it : s[nmax - 1]) {
		write(it.first);
		cout << " ";
		write(it.second);
		cout << "\n";
	}*/
	//cout << sz(s[nmax - 1]) << "\n";

}