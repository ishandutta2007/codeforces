// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
const int S = 1000001, M = 500000;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define Ssecond

ll n, a[MAXN], b, l;
bool v[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> b;
		if(b <= M){
			a[b]++;
			v[b] = 1;
		}
		else{
			a[S - b]++;
		}
	}
	
	l = 1;
	
	cout << n << endl;
	
	for(ll i = 1; i <= M; i++){
		if(a[i] == 1){
			if(v[i]){
				cout << S - i << " ";
			}
			else{
				cout << i << " ";
			}
		}
		else if(a[i] == 2){
			while(a[l] != 0){
				l++;
			}
			cout << l << " " << S - l << " ";
			l++;
		}
	}
	
	return 0;
}