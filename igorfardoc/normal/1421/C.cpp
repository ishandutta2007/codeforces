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
    string s;
    cin >> s;
    int n = s.size();
    cout << 3 << '\n';
    cout << "R " << n - 1 << '\n';
    cout << "L " << n << '\n';
    cout << "L " << 2 << '\n';
}