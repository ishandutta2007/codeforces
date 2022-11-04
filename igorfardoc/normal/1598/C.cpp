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
    	ll sum = 0;
    	int n;
    	cin >> n;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		sum += a[i];
    	}
    	int mid;
    	int adding = 0;
    	if(sum % n == 0) {
    		mid = sum / n;
    	} else if(sum * 2 % n == 0) {
    		mid = sum / n;
    		adding = 1;
    	} else {
    		cout << "0\n";
    		continue;
    	}
    	map<int, int> am;
    	ll res = 0;
    	for(int i = 0; i < n; i++) {
    		int here = a[i];
    		int need;
    		if(here <= mid) {
    			need = 2 * mid - here + adding;
    		} else {
    			need = 2 * mid - here + adding;
    		}
    		//cout << here << ' ' << need << ' ' << mid << ' ' << adding << endl;
    		res += am[need];
    		++am[here];
    	}
    	cout << res << '\n';
    }
}