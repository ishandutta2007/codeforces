#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif



int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; 
		cin >> n;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		int lo = 0, hi = n;
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			int taken = 0;
			for(int i = 0; i < n && taken < mid; i++){
				if(taken <= b[i] && mid - taken - 1 <= a[i]){
					taken++;
				}
			}
			if(taken == mid){
				lo = mid;
			} else hi = mid - 1;
		}
		cout << lo << endl;
	}
}