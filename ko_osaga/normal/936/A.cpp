#include <bits/stdc++.h>
using namespace std;
const int MAXL = 20;
const int MAXN = 300005;
using lint = long long;
using pi = pair<int, int>;

lint k, d, t;

lint trial(lint x){
//	cout << "f(" << x << ")=";
	lint rep = (x / (2 * d));
	x %= 2 * d;
	rep *= (2 * k + d - k);
	rep += min(x, 2 * k);
	x -= min(x, 2 * k);
	rep += x / 2;
//	cout << rep << endl;
	return rep;
}

int main(){
	cin >> k >> d >> t;
	d *= (k + d - 1) / d;
	// ontime = k, offtime = d - k
	lint s = 0, e = 4e18;
	while(s != e){
		lint m = (s+e)/2;
		if(trial(m) < 2 * t) s = m + 1;
		else e = m;
	}
	printf("%.1f\n", s * 0.5);
}