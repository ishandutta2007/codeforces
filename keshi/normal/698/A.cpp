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
#define F first
#define S second

int n, c, ans, j;
bool a[MAXN][2];

int main(){
	fast_io;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c;
		a[i][0] = c & 1;
		a[i][1] = (c >> 1) & 1;
	}
	for(int i = 0; i < n; i++){
		if(i > 0 && a[i - 1][0]){
			a[i][0] = 0;
		}
		if(i > 0 && a[i - 1][1]){
			a[i][1] = 0;
		}
		if(i < n - 1 && a[i][0] && a[i][1]){
			j = i + 1;
			while(j < n && a[j][0] && a[j][1]){
				j++;
			}
			if(j != n){
				if((j - i) % 2){
					if(a[j][0]){
						a[i][0] = 0;
					}
					else{
						a[i][1] = 0;
					}
				}
				else{
					if(a[j][0]){
						a[i][1] = 0;
					}
					else{
						a[i][0] = 0;
					}
				}
			}
			else{
				a[i][0] = 0;
			}
		}
		if(!a[i][0] && !a[i][1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}