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
    	ll x;
    	int s;
    	cin >> x >> s;
    	int sum = 0;
    	ll now = x;
    	vi ch;
    	while(now) {
    		sum += now % 10;
    		ch.push_back(now % 10);
    		now /= 10;
    	}
    	if(sum <= s) {
    		cout << 0 << '\n';
    		continue;
    	}
    	ch.push_back(0);
    	reverse(ch.begin(), ch.end());
    	ll here = 10;
    	now = 0;
    	for(int i = ch.size() - 1; i >= 0; i--) {
    		now += here / 10 * ch[i];
    		if(sum - ch[i] + 1 <= s) {
    			cout << here - now << '\n';
    			break;
    		}
    		sum -= ch[i];
    		here *= 10;
    	}
    }

}