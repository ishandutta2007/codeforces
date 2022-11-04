#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

string get(string s, int l, int r) {
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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	string s;
    	cin >> n >> s;
    	if(s == "2020") {
    		cout << "YES\n";
    		continue;
    	}
    	if(get(s, 0, 3) == "2020" || (get(s, 0, 2) == "202" && get(s, n - 1, n - 1) == "0") || (get(s, 0, 1) == "20" && get(s, n - 2, n - 1) == "20") || (get(s, 0, 0) == "2" && get(s, n - 3, n - 1) == "020") || get(s, n - 4, n - 1) == "2020") {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}