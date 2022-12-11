#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<int> p_func(const string& s) {
	int n = sz(s);
	vector<int> p(n);
	for (int i = 1; i < sz(s); ++i) {
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = p[j - 1];
		}
		if (s[j] == s[i]) {
			++j;
		}
		p[i] = j;
	}
	return p;
}

int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
                                               
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<int> p = p_func(s);
    set<int> setik;
    for (int i = 1; i < sz(s) - 1; ++i) {
    	setik.insert(p[i]);
    }

    int j = p.back();
    while (j > 0 && !setik.count(j)) {
    	j = p[j - 1];
    }
    if (setik.count(j) && j > 0) {
    	cout << s.substr(0, j) << "\n";
    } else {
    	cout << "Just a legend\n";
    }

}