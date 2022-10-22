#include <bits/stdc++.h>
using namespace std;

int t, n, d[(int) 3e5 + 5], k, l;

int main(){
	cin >> t; while (t--){
		cin >> n >> k >> l;
		vector<int> sf; 
		sf.push_back(0);
		for (int i = 1; i <= n; i++){
			cin >> d[i];
			if (d[i] + k <= l)
				sf.push_back(i);
		}
		sf.push_back(n+1);
		
		bool ok = true, dw; int td; 
		for (int i = 1; i < sf.size() && ok; i++){
			dw = true; td = k;
			for (int j = sf[i-1] + 1; j < sf[i]; j++){
				td += dw ? -1 : 1;

				if (dw) td -= max(0, d[j] + td - l);
				if (td < 0 || d[j] + td > l) { 
				    cout << "NO\n";
				    ok = false; 
				    break; 
				}
				if (td == 0) dw = false;
			}
		}

		if (ok) cout << "YES\n";
	}

	return 0;
}