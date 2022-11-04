#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    	cin >> n;
    	unordered_set<int> s;
    	for(int i = 1; i * i <= n; i++) {
    		s.insert(i * i);
    	}
    	for(int i = 1; i * i * i <= n; i++) {
    		s.insert(i * i * i);
    	}
    	cout << s.size() << '\n';
    }
}