#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int cnt[256];
string a;

int dp[2605][2605];

int f(int s, int e){
	if(s > e) return 0;
	if(s == e) return 1;
	if(~dp[s][e]) return dp[s][e];
	int ret = max(f(s+1, e), f(s, e-1));
	if(a[s] == a[e]) ret = max(ret, f(s+1, e-1) + 2);
	return dp[s][e] = ret;
}

string l, r;

void track(int s, int e){
	if(s > e) return;
	if(s == e){
		l.push_back(a[s]);
		return;
	}
	if(f(s, e) == f(s+1, e)){
		track(s+1, e); return;
	}
	if(f(s, e) == f(s, e-1)){
		track(s, e-1); return;
	}
	if(a[s] == a[e]){
		l.push_back(a[s]);
		r.push_back(a[e]);
		track(s+1, e-1);
		return;
	}
}

int main(){
	cin >> a;
	for(auto &i : a){
		cnt[i]++;
	}
	int p = max_element(cnt, cnt + 256) - cnt;
	if(cnt[p] >= 100){
		for(int i=0; i<100; i++) putchar(p);
		return 0;
	}
	int n = a.size();
	memset(dp, -1, sizeof(dp));
	f(0, n-1);
	track(0, n-1);
	reverse(r.begin(), r.end());
	l = l + r;
	if(l.size() > 100){
		for(int i=0; i<50; i++){
			putchar(l[i]);
		}
		for(int i=49; i>=0; i--){
			putchar(l[l.size()-i-1]);
		}
		return 0;
	}
	cout << l;
}