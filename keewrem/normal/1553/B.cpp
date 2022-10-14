#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
	string s,t;
	cin >> s >> t;
	int N,M;
	N = s.size(), M = t.size();
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			if(2*i-j+1 < M)continue;
			int c = 0;
			bool p = 1;
			for(int k = j; k < i; k++){
				if(c >= M)break;
				if(s[k] != t[c++])p = 0;
			}
			for(int k = i; k >= 0; k--){
				if(c >= M)break;
				if(s[k] != t[c++])p = 0;
			}
			if(p){cout << "YES\n"; return;}
		}
	}
	cout << "NO\n";
	return;
}

int main(){
  int T;
    cin >> T;
    while(T--){
        solve();
    }
}