#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, xs, ys, xe, ye, x, y, d[4];
ll cnt;
pll p[100];

int main(){
	fast_io;
	cin >> n;
	n = 4 * n + 1;
	for(ll i = 0; i < n; i++){
		cin >> p[i].X >> p[i].Y;
	}
	for(ll j = 0; j < n; j++){
		xe = -1;
		xs = 100;
		ye = -1;
		ys = 100;
		for(ll k = 0; k < n; k++){
			if(k != j){
				xs = min(xs, p[k].X);
				xe = max(xe, p[k].X);
				ys = min(ys, p[k].Y);
				ye = max(ye, p[k].Y);
			}
		}
		fill(d, d + 4, 0);
		//cout << xs << "_" << ys << " " << ys << "_" << ye << endl;
		cnt = 0;
		for(ll i = 0; i < n; i++){
			if(i == j){
				continue;
			}
			x = p[i].X;
			y = p[i].Y;
			
			if(x == xs){
				d[0]++;
			}
			if(x == xe){
				d[1]++;
			}
			if(y == ys){
				d[2]++;
			}
			if(y == ye){
				d[3]++;
			}
			if(x == xs || x == xe){
				if(y < ys || y > ye){
					cnt++;
				}
			}
			else if(y == ys || y == ye){
				if(x < xs || x > xe){
					cnt++;
				}
			}
			else{
				cnt++;
			}
		}
		//cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << endl;
		if(cnt == 0 && d[0] >= n / 4 && d[1] >= n / 4 && d[2] >= n / 4 && d[3] >= n / 4){
			cout << p[j].X << ' ' << p[j].Y;
			return 0;
		}
	}
	return 0;
}