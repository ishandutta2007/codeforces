#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, x;
multiset<ll> st;
bool tag = false;

void solve(ll sum){
	if(tag || st.empty()) return;
	if(st.find(sum) != st.end()){
		st.erase(st.find(sum));
		return;
	}
	if(sum == 1){
		tag = true;
		return;
	}
	solve(sum / 2), solve((sum + 1) / 2);
}

void solve(){
	st.clear();
	scanf("%d", &n);
	ll sum = 0;
	while(n--) scanf("%d", &x), st.insert(x), sum += x;
	tag = false;
	solve(sum);
}

int main(){
	scanf("%d", &t);
	while(t--) solve(), puts(!tag ? "YES" : "NO");
}