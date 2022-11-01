#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    string s,t,p;
	cin >> s >> t >> p;
	int s_freq[26] = {0}, t_freq[26] = {0}, p_freq[26] = {0};
	for (int i = 0; i < s.size(); i++) s_freq[s[i] - 'a']++;
	for (int i = 0; i < t.size(); i++) t_freq[t[i] - 'a']++;
	for (int i = 0; i < p.size(); i++) p_freq[p[i] - 'a']++;
	// check if subsequence 
	int i = 0, j = 0;
	while (i < s.size() && j < t.size()) {
		int k = j;
		bool ans = false;
		for (; k < t.size(); k++) {
			if (s[i] == t[k]) {
				i++;
				ans = true;
				j = k + 1;
				break;
			}
		}
		if (!ans) {
			cout << "NO\n";
			return;
		}
	}
	if (i < s.size()) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (t_freq[i]) {
			if (s_freq[i] + p_freq[i] < t_freq[i]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	return;
}

int main(){
    int q;
    cin>>q;
    // q = 1;
    while(q--) {
        solve();
    }
    return 0;
}