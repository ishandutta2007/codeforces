#include<bits/stdc++.h>
#define N 10000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[N + 1];



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vi pr;
    for(int i = 2; i <= N; i++) {
    	if(lp[i] == 0) {
    		lp[i] = i;
    		pr.push_back(i);
    	}
    	for(int j = 0; j < pr.size() && i * pr[j] <= N && lp[i] >= pr[j]; j++) {
    		lp[i * pr[j]] = pr[j];
    	}
    }
    int n;
    cin >> n;
    vi a(n, -1);
    vi b(n, -1);
    for(int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if(x % 2 == 0) {
    		while(x % 2 == 0) {
    			x /= 2;
    		}
    		if(x != 1) {
    			a[i] = 2;
    			b[i] = x;
    		}
    	} else {
    		int now = lp[x];
    		while(lp[x] == now) {
    			x /= now;
    		}
    		if(lp[x] != 0) {
    			a[i] = lp[x];
    			b[i] = now;
    		}
    	}
    }
    for(int i = 0; i < n; i++) {
    	cout << a[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++) {
    	cout << b[i] << ' ';
    }
}