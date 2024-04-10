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
    int n;
    cin >> n;
    vi after(n, -1);
    int start = -1;
    for(int i = 0; i < n; i++) {
    	cout << "? ";
    	for(int j = 0; j < n; j++) {
    		if(j == i) {
    			cout << 1 << ' ';
    		} else {
    			cout << 2 << ' ';
    		}
    	}
    	cout << endl;
    	int k;
    	cin >> k;
    	--k;
    	if(k == -1) {
    		start = i;
    		continue;
    	}
    	if(k != i) {
    		after[k] = i;
    	}
    }
    for(int i = 0; i < n; i++) {
    	cout << "? ";
    	for(int j = 0; j < n; j++) {
    		if(j == i) {
    			cout << 2 << ' ';
    		} else {
    			cout << 1 << ' ';
    		}
    	}
    	cout << endl;
    	int k;
    	cin >> k;
    	--k;
    	if(k == -1) {
    		continue;
    	}
    	if(k != i) {
    		after[i] = k;
    	}
    }
    cout << "! ";
    vi ans(n);
    for(int i = 0; i < n; i++) {
    	ans[start] = i;
    	start = after[start];
    }
    for(int i = 0; i < n; i++) {
    	cout << ans[i] + 1 << ' ';
    }
    cout << endl;
}