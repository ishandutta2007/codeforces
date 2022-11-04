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
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int l = 0;
    int r = n - 1;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; i++) {
    	int here;
    	if(a[l] > a[r]) {
    		here = a[l];
    		++l;
    	} else {
    		here = a[r];
    		--r;
    	}
    	if(i % 2 == 0) {
    		sum1 += here;
    	} else {
    		sum2 += here;
    	}
    }
    cout << sum1 << ' ' << sum2;
}