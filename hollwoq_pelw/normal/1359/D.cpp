#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> a, int top, int n, int &ans){
	int chk = 0, cnt = 0, res = 0;
	for(int i = 0; i < n; ++i){
		cnt += a[i];
		if(a[i] == top) 
		    chk = 1;
		if(cnt < 0 || a[i] > top){
			chk = 0;
			cnt = 0;
		}if(chk == 1){
			res = max(res, cnt - top);
		}
	}
	ans = max(ans, res);
}
int main(){
    int n, ans = 0; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int t = 1; t <= 30; t ++){
        solve(a, t, n, ans);
    }
    cout << ans;
}