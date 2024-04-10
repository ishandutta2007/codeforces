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
    int x, y, z;
    cin >> x >> y >> z;
    if(x - z > y) {
    	cout << "+";
    	return 0;
    }
    if(y - z > x) {
    	cout << "-";
    	return 0;
    }
    if(x == y && z == 0) {
    	cout << "0";
    	return 0;
    }
    cout << "?";
}