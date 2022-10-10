#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, d;
	cin >> n >> m >> d;
	int a, b, tprev;
	cin >> a >> b >> tprev;
	priority_queue<long long> left{{}, vector<long long>{a}};
	priority_queue<long long, vector<long long>, greater<>> right{greater<>(), vector<long long>{a}};
	long long lshift = 0;
	long long rshift = 0;
	long long res = b;
	for(auto rep = m - 1; rep; -- rep){
		int a, b, t;
		cin >> a >> b >> t;
		lshift -= 1LL * d * (t - tprev);
		rshift += 1LL * d * (t - tprev);
		res += b;
		if(a <= left.top() + lshift){
			res += a - left.top() - lshift;
			right.push(left.top() + lshift - rshift);
			left.pop();
			left.push(a - lshift);
			left.push(a - lshift);
		}
		else if(a <= right.top() + rshift){
			left.push(a - lshift);
			right.push(a - rshift);
		}
		else{
			res += right.top() + rshift - a;
			left.push(right.top() + rshift - lshift);
			right.pop();
			right.push(a - rshift);
			right.push(a - rshift);
		}
		tprev = t;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////