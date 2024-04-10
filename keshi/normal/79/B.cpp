#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
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

ll n, m, k, t, a[MAXN][2], ans, x, y;


int main(){
	fast_io;
	
	cin >> n >> m >> k >> t;
	
	for(int i = 0; i < k; i++){
		cin >> a[i][0] >> a[i][1];
	}
	
	for(int i = 0; i < t; i++){
		cin >> x >> y;
		ans = (x - 1) * m + y;
		for(int j = 0; j < k; j++){
			if(a[j][0] < x || (a[j][0] == x && a[j][1] < y)){
				ans--;
			}
			if(a[j][0] == x && a[j][1] == y){
				ans = -1;
				break;
			}
		}
		if(ans == -1){
			cout << "Waste";
		}
		else if(ans % 3 == 0){
			cout << "Grapes";
		}
		else if(ans % 3 == 1){
			cout << "Carrots";
		}
		else{
			cout << "Kiwis";
		}
		cout << endl;
	}
	
	return 0;
}