// Hydro submission #6229adabe016cd75c1b4cf81@1646898603385
#include<bits/stdc++.h>



using namespace std;

typedef long long ll;

const int N = 201000, MAXN = 200100;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
int a[1001000];

int lupper[1001000], rupper[1001000];
int rlower[1001000], llower[1001000];

void slove() {
	ll ans = 0;
	int n; cin >> n;
	stack<pair<int, int>> st, st2, st3, st4;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		while(!st.empty() && st.top().first <= a[i]){
			rupper[st.top().second] = i - 1;
			st.pop();
		}
		st.push({a[i], i});
	}  
	for(int i = n; i >= 1; i--){
		while(!st2.empty() && st2.top().first < a[i]){
			lupper[st2.top().second] = i + 1;
			// cout << "lupper[" << st.top().second << ']' << "   " << i + 1 << '\n';
			st2.pop();
		}
		st2.push( {a[i], i} );
	}
	for(int i = 1; i <= n; i++){
		while(!st3.empty() && st3.top().first > a[i]){
			rlower[st3.top().second] = i - 1;
			st3.pop();
		}
		st3.push({a[i], i});
	}
	for(int i = n; i >= 1; i--){
		while(!st4.empty() && st4.top().first >= a[i]){
			llower[st4.top().second] = i + 1;
			st4.pop();
		}
		st4.push({a[i], i});
	}
	for(int i = 1; i <= n; i++){
		ll lup = lupper[i], rup = rupper[i];
		if(lupper[i] == 0) lup = 1;
		if(rupper[i] == 0) rup = n;
		ll llow = llower[i], rlow = rlower[i];
		if(llower[i] == 0) llow = 1;
		if(rlower[i] == 0) rlow = n;
		
		ans += a[i] * (rup - lup + 1 + (rup - i) * (i - lup)) - a[i] * (rlow - llow + 1 + (rlow - i) * (i - llow));
		// cout << ans << '\n';
		// cout << lup << "   " << rup << '\n';
		// cout << llow << "   " << rlow << '\n';
		// cout << i << "    " << ans << '\n';
		// cout << '\n';
	}
	cout << ans << '\n';

}




int main(){
    // ios_base::sync_with_stdio(0), cin.tie(0);
    slove();
    
}