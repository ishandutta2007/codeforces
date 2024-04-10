//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 100;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define pb push_back
#define pll pair<ll, ll>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F first
#define S second

ll n, a[MAXN], m[MAXN][4], ans;

vector<ll> s;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	s.clear();
	for(ll i = 0; i < n; i++){
		while(!s.empty() && a[s.back()] < a[i]){
			s.pop_back();
		}
		if(!s.empty()){
			m[i][0] = s.back();
		}
		else{
			m[i][0] = -1;
		}
		s.pb(i);
	}
	
	s.clear();
	for(ll i = n - 1; i > -1; i--){
		while(!s.empty() && a[s.back()] <= a[i]){
			s.pop_back();
		}
		if(!s.empty()){
			m[i][1] = s.back();
		}
		else{
			m[i][1] = n;
		}
		s.pb(i);
	}
	
	s.clear();
	for(ll i = 0; i < n; i++){
		while(!s.empty() && a[s.back()] > a[i]){
			s.pop_back();
		}
		if(!s.empty()){
			m[i][2] = s.back();
		}
		else{
			m[i][2] = -1;
		}
		s.pb(i);
	}
	
	s.clear();
	for(ll i = n - 1; i > -1; i--){
		while(!s.empty() && a[s.back()] >= a[i]){
			s.pop_back();
		}
		if(!s.empty()){
			m[i][3] = s.back();
		}
		else{
			m[i][3] = n;
		}
		s.pb(i);
	}
	
	for(ll i = 0; i < n; i++){
		ans += (m[i][1] - i) * (i - m[i][0]) * a[i] - (m[i][3] - i) * (i - m[i][2]) * a[i];
	}
	
	cout << ans;
	
	return 0;
}