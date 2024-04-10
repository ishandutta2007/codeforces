#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;


#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long n, a[MAXN], ans;
vector<long long> s;

int main(){
	fast_io;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	s.push_back(a[0]);
	
	for(int i = 1; i < n; i++){
		while(!s.empty() && s.back() < a[i]){
			ans = max(ans, a[i]^s.back());
			s.pop_back();
		}
		if(!s.empty()){
			ans = max(ans, a[i]^s.back());
		}
		s.push_back(a[i]);
	}
	
	cout << ans;
	
	return 0;
	
}