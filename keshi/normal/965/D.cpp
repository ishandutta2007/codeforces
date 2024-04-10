#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, l, v, a[MAXN], b[MAXN], ans, nex[MAXN], pre[MAXN];


int main(){
	fast_io;
	
	cin >> n >> l;
	cin >> a[1];
	
	for(ll i = 2; i < n; i++){
		cin >> a[i];
		if(a[i - 1]){
			pre[i] = i - 1;
		}
		else{
			pre[i] = pre[i - 1];
		}
	}
	
	for(ll i = n - 1; i > 0; i--){
		if(a[i + 1]){
			nex[i] = i + 1;
		}
		else{
			nex[i] = nex[i + 1];
		}
	}
	
	for(ll i = 1; i <= l; i++){
		b[i] = a[i];
		a[i] = 0;
	}
	
	for(ll i = 1; i <= n; i++){
		if(i + l >= n){
			ans += b[i];
		}
		else{
			if(a[i + l]){
				v = i + l;
			}
			else{
				v = pre[i + l];
			}
			while(b[i] && v > i){
				if(a[v] > b[i]){
					a[v] -= b[i];
					b[v] += b[i];
					b[i] = 0;
				}
				else{
					b[v] += a[v];
					pre[nex[v]] = pre[v];
					b[i] -= a[v];
					a[v] = 0;
					v = pre[v];
				}
			}
		}
	}
	
	cout << ans;
	
	return 0;
}