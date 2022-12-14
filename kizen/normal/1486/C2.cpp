#include <bits/stdc++.h>

using namespace std;

void out(int s, int e){
	cout << "? " << s << ' ' << e << '\n';
	cout.flush();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	out(1, n);
	int rv; cin >> rv;
	int sv;
	if(rv == 1){
		sv = -1;
	}
	else{
		out(1, rv);
		cin >> sv;
	}
	if(rv != sv){
		int l = rv + 1, r = n, mid;
		while(l < r){
			int mid = (l + r) >> 1;
			out(1, mid);
			int val; cin >> val;
			if(rv == val){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
        cout << "! " << l << '\n';
        cout.flush();
	}
	else{
		int l = 1, r = rv - 1, mid;
		while(l < r){
			int mid = (l + r) >> 1; ++mid;
			out(mid, n);
			int val; cin >> val;
			if(rv == val){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
        cout << "! " << l << '\n';
        cout.flush();
	}
	return 0;
}