#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 15

int n;
char a[NMAX][NMAX], b[NMAX][NMAX], aux[NMAX][NMAX];

bool equal() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i][j] != b[i][j])
				return false;
	
	return true;
}

void flipVert() {
	for(int i = 0; i < n; ++i)
		reverse(a[i], a[i] + n);
}

void flipHoriz() {
	for(int i = 0; i < n - 1 - i; ++i)
		for(int j = 0; j < n; ++j)
			swap(a[i][j], a[n - 1 - i][j]);
}

void rotateMat() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			aux[n - 1 - j][i] = a[i][j];
		}
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			a[i][j] = aux[i][j];
		}
}

bool bkt(bool horiz, bool vert, bool rotate) {
	if(equal()) return true;
	
	if(!horiz) {
		flipHoriz();
		if(bkt(true, vert, rotate)) return true;
		flipHoriz();
	}
	
	if(!vert) {
		flipVert();
		if(bkt(horiz, true, rotate)) return true;
		flipVert();
	}
	
	if(!rotate) {
		for(int i = 1; i <= 3; ++i) {
			rotateMat();
			if(bkt(horiz, vert, true)) return true;
		}
		
		rotateMat();
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	
	if(bkt(false, false, false)) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}