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
    int n, s;
    cin >> n >> s;
    int sum = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	mx = max(mx, a);
    	sum += a;
    }
    sum -= mx;
    if(sum <= s) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
}