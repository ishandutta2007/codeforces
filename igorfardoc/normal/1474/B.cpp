#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[100000];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vector<int> pr;
    for(int i = 2; i < 100000; i++) {
    	if(lp[i] == 0) {
    		pr.push_back(i);
    		lp[i] = i;
    	}
    	for(int j = 0; j < pr.size() && i * pr[j] < 100000 && pr[j] <= lp[i]; j++) {
    		lp[i * pr[j]] = pr[j];
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int d;
    	cin >> d;
    	ll ans = 1;
    	int id1 = lower_bound(pr.begin(), pr.end(), d + 1) - pr.begin();
    	ans *= pr[id1];
    	id1 = lower_bound(pr.begin(), pr.end(), d + pr[id1]) - pr.begin();
    	ans *= pr[id1];
    	cout << ans << '\n';
    }
}