#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool is_perm(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

bool is_subseq(string a, string b) {
	size_t j = 0;
	for (char x : a) {
		if (j != b.size() && x == b[j])
			j++;
	}
	return j == b.size();
}

bool is_subset(string a, string b) {
	vector<int> cnt(26, 0);
	for (char x : a)
		cnt[x-'a']++;
	for (char x : b)
		cnt[x-'a']--;
	for (int i=0; i<26; i++)
		if (cnt[i] < 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s, p;
	cin >> s >> p;
	if (is_perm(s, p)) {
		cout << "array\n";
	} else if (is_subseq(s, p)) {
		cout << "automaton\n";
	} else if (is_subset(s, p)) {
		cout << "both\n";
	} else {
		cout << "need tree\n";
	}
}