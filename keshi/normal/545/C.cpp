// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define H second

ll n, L[MAXN], R[MAXN], U[MAXN];
pll a[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].X >> a[i].H;
	}
	
	if(n == 1){
		cout << 1;
		return 0;
	}
	
	L[0] = 1;
	U[0] = 0;
	if(a[0].X + a[0].H < a[1].X){
		R[0] = 1;
	}
	
	a[n].X = INF;
	
	for(ll i = 1; i < n; i++){
		U[i] = max(U[i - 1], max(L[i - 1], R[i - 1]));
		if(a[i].X - a[i].H <= a[i - 1].X){
			L[i] = -1;
		}
		else{
			if(a[i - 1].X + a[i - 1].H >= a[i].X - a[i].H){
				L[i] = max(U[i - 1], L[i - 1]) + 1;
			}
			else{
				L[i] = max(U[i - 1], max(L[i - 1], R[i - 1])) + 1;
			}
		}
		if(a[i].X + a[i].H >= a[i + 1].X){
			R[i] = -1;
		}
		else{
			R[i] = max(U[i - 1], max(L[i - 1], R[i - 1])) + 1;
		}
	}
	
	cout << max(L[n - 1], max(U[n - 1], R[n - 1]));
	
	return 0;
}