#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans;
string s[MAXN];
bool f[MAXN], k;


int main(){
	fast_io;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < m; i++){
		k = 0;
		for(int j = 1; j < n; j++){
			if(!f[j]){
				if(s[j][i] < s[j - 1][i]){
					k = 1;
					break;
				}
			}
		}
		if(k){
			ans++;
			continue;
		}
		for(int j = 1; j < n; j++){
			if(!f[j]){
				if(s[j][i] > s[j - 1][i]){
					f[j] = 1;
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}