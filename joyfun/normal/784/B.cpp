#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;++i)

int cnt(int x){
	if(x == 0) return 1;
	if(x == 4) return 1;
	if(x == 6) return 1;
	if(x == 8) return 2;
	if(x == 9) return 1;
	if(x == 10) return 1;
	if(x == 11) return 2;
	if(x == 13) return 1;
	return 0;
}

int main(){
	int x,y;
	while(cin >> x){
		int ans = 0;
		if(x == 0) ans = 1;
		while(x){
			ans += cnt(x % 16);
			x /= 16;
		}
		cout << ans << endl;
	}
	return 0;
}