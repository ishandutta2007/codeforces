#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
	string s,t;
	cin >> s >> t;
	int N = s.size(), M = t.size();
	reverse(all(s));
	reverse(all(t));
	int ind = 0;
	for(int i = 0; i < M; i++){
		if(ind >= N){cout << "NO\n"; return;}
		while(t[i] != s[ind]){
			ind += 2;
			if(ind >= N){cout << "NO\n"; return;}
		}
		ind++;
	}
	cout << "YES\n";
 	return;
}

int main(){
  int T;
    cin >> T;
    while(T--){
        solve();
    }
}