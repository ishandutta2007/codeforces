#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ind second

#define ll long long

ll n, m, a[MAXN], c[MAXN], t, d, k, o, ans;

priority_queue< pair<int, int> > p;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		p.push({-c[i], -i});
	}
	while(m--){
		cin >> d >> t;
		k = min(t, a[d]);
		ans = k * c[d];
		a[d] -= k;
		t -= k;
		//cout << "# " << d << ' ' << k << endl;
		while(t){
			if(p.empty()){
				ans = 0;
				break;
			}
			d = -p.top().ind;
			k = min(t, a[d]);
			ans += k * c[d];
			a[d] -= k;
			t -= k;
			//cout << "# " << d << ' ' << k << endl;
			if(a[d] == 0){
				p.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}