#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, s, sl, sr, l[30], r[30], d;

int main(){
	fast_io;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		sl += l[i];
		sr += r[i];
	}
	if(s > sr || s < sl){
		cout << "NO";
	}
	else{
		s = s - sl;
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			d = min(s, r[i] - l[i]);
			cout << l[i] + d << " ";
			s -= d;
		}
	}
	return 0;
}