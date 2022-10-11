#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define R first
#define L second

ll n, a[MAXN], cnt[MAXN], x, g;
bool t;

int main(){
	fast_io;
	
	cin >> n;
	
	g = -1;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] > 2){
			g = i;
		}
	}
	
	for(ll i = 0; i < MAXN; i++){
		if(cnt[i] == 1){
			x++;
		}
	}
	
	if(x == 0){
		cout << "YES" << endl;
		for(ll i = 0; i < n; i++){
			if(cnt[a[i]] == 2){
				cout << 'B';
				cnt[a[i]]--;
			}
			else{
				cout << 'A';
			}
		}
		return 0;
	}
	
	if(x % 2){
		if(g == -1){
			cout << "NO";
			return 0;
		}
	}
	else{
		g = -1;
	}
	
	cout << "YES" << endl;
	
	for(ll i = 0; i < n; i++){
		if(cnt[a[i]] == 1){
			if(t){
				cout << 'A';
			}
			else{
				cout << 'B';
			}
			t = !t;
		}
		else if(i == g){
			cout << 'A';
		}
		else{
			cout << 'B';
		}
	}
	
	return 0;
}