#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define magic_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>

int n, m, k, s, r, l;


int main(){
	magic_io;
	cin >> n >> m >> k;
	s = n * m;
	for(int x = 1; x <= n; x++){
		if(x % 2){
			for(int y = m; y > 0; y--){
				if(r == 0){
					r = s / k;
					s -= r;
					k--;
					cout << r << ' ';
				}
				cout << x << ' ' << y << ' ';
				r--;
				if(r == 0){
					cout << endl;
				}
			}
		}
		else{
			for(int y = 1; y <= m; y++){
				if(r == 0){
					r = s / k;
					s -= r;
					k--;
					cout << r << ' ';
				}
				cout << x << ' ' << y << ' ';
				r--;
				if(r == 0){
					cout << endl;
				}
			}
		}
	}
	return 0;
}