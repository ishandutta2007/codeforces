#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, k;
		cin >> N >> k;
		vector<int> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		int l = a[0], r = a[0], f = 0;
		for(int i = 1; i < N; ++i){
			int nl = a[i], nr = a[i] + k - 1;
			int ml = l - k + 1, mr = r + k - 1;
			if(mr < nl || ml > nr){
				f = 1;
				break;
			}
			l = max(nl, ml), r = min(nr, mr);
		}
		if(f || a[N - 1] < l || a[N - 1] > r){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}