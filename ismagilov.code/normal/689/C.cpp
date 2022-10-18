#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

ll keke(ll xi){
	ll ans = 0;
	for (ll i = 2; (i*i*i) <= xi; i++){
		ans += (xi / (i*i*i));
	}
	return ans;
}

int main() {
	ll ma;
	cin >> ma;
	ll ri = 1;
	ll li = 10000000000000000;
	while((li - ri) > 1){
		
		//cout << li << ' ' << ri << ' ' << keke(li) << endl;
		ll midi = (li+ri) / 2;
		if (keke(midi) >= ma){
			li = midi;
		}
		else{
			ri = midi;
		}
		//cout << li << ' ' << ri << ' ' << midi << ' ' << keke(midi) << endl;
	}
	if (keke(li) == ma)
		cout << li;
	else
		cout << -1;
}