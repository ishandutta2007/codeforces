// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct eertree {
	struct node {
		int link, len;
		map<char, int> next;
	};

	vector<node> b;
	string s;
	int last;

	eertree() {
		b.push_back({0, -1, {}});
		b.push_back({0, 0, {}});
		last = 1;
	}

	void extend(char x) {
		s += x;
		int curr = last;
		while (1) {
			int pos = s.size() - b[curr].len - 2;
			if (pos >= 0 && s[pos] == x)
				break;
			curr = b[curr].link;
		}
		if (b[curr].next.count(x)) {
			last = b[curr].next[x];
			return;
		}
		int link;
		if (curr == 0) { // jedno slovo
			link = 1; // suffix link je ka len=0
		} else {
			link = curr;
			while (1) {
				link = b[link].link;
				int pos = s.size() - b[link].len - 2;
				if (pos >= 0 && s[pos] == x) {
					link = b[link].next[x];
					break;
				}
			}
		}
		last = b.size();
		b[curr].next[x] = last;
		b.push_back({link, b[curr].len + 2, {}});
	}
};

vector<int> duzine(const string& s) {
	int n = s.size();
	vector<int> v(n+1);
	eertree drvo;
	for (int i=0; i<n; i++) {
		drvo.extend(s[i]);
		v[i+1] = drvo.b[drvo.last].len;
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string r = s;
		int n = s.size();
		reverse(begin(r), end(r));
		
		int k = 0;
		while (2*k+2 <= n && s[k] == s[n-1-k])
			k++;

		auto fwd = duzine(s.substr(k, n-k-k));
		auto bck = duzine(r.substr(k, n-k-k));

		int p = 0, q = 0;

		if (fwd.back() > bck.back())
			q = k + fwd.back(), p = k;
		else
			q = k, p = k + bck.back();
		cout << s.substr(0, p) << s.substr(n-q, q) << '\n';
	}
}

// I will still practice daily...

// abcecdfdcba|abcecdfdcba

// acbba|acbba