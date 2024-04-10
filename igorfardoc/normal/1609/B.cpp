#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int calc(string s) {
	int n = s.size();
	int ans = 0;
	for(int i = 0; i < n - 2; i++) {
		if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			++ans;
		}
	}
	return ans;
}

string get_s(string& s, int l, int r) {
	string res = "";
	for(int i = l; i <= r; i++) {
		res += s[i];
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = calc(s);
    for(int i = 0; i < q; i++) {
    	int id1;
    	char c;
    	cin >> id1 >> c;
    	--id1;
    	ans -= calc(get_s(s, max(0, id1 - 5), min(n - 1, id1 + 5)));
    	s[id1] = c;
    	ans += calc(get_s(s, max(0, id1 - 5), min(n - 1, id1 + 5)));
    	cout << ans << '\n';
    }

}