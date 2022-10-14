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
	string k;
	cin >> k;
	string s = k;
	int r = 10;
	// vince la seconda
	for(int i = 0; i < 10; i++){
		if(k[i] == '?')s[i] = '0'+i%2;
	}
	int d = 0;
	for(int i = 0; i < 10; i++){
		if(i%2)d += s[i]-'0';
		else d -= s[i]-'0';
		if(d > (9-i)/2)r = min(r,i+1);
	}
	for(int i = 0; i < 10; i++){
		if(k[i] == '?')s[i] = '1'-i%2;
	}
	d = 0;
	for(int i = 0; i < 10; i++){
		if(i%2)d -= s[i]-'0';
		else d += s[i]-'0';
		if(d > (10-i)/2)r = min(r,i+1);
	}
	cout << r << endl;
  return;
}

int main(){
  int T;
    cin >> T;
    while(T--){
        solve();
    }
}