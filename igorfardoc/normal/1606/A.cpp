#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
string s;
bool is_ab(int i) {
	if(s[i] == 'a' && s[i + 1] == 'b') {
		return true;
	}
	return false;
}
bool is_ba(int i) {
	if(s[i] == 'b' && s[i + 1] == 'a') {
		return true;
	}
	return false;
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
    	cin >> s;
    	int n = s.size();
    	s[n - 1] = s[0];
    	cout << s << '\n';
    }
}