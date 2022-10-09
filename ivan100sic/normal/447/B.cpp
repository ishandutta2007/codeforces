#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int w[26];
string s;
int k, z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> k;
	for (int i=0; i<26; i++)
		cin >> w[i];
	for (int i=0; i<(int)s.size(); i++)
		z += w[s[i]-'a'] * (i+1);
	for (int i=0; i<k; i++)
		z += (s.size() + i + 1) * *max_element(w, w+26);
	cout << z << '\n';
}