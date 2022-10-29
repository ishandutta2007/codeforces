#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, PII> PIP;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

map<int, PIP> mp1, mp2;
int Q;

void read(){
	scanf("%d%d%d", &n, &m, &Q);
}

int Noc(int x, int y){
	if (x == 0 && y == 0) return 0;
	if (x == 0 && y == m) return 0;
	if (x == n && y == 0) return 0;
	if (x == n && y == m) return 0;
	return 1;
}

void solve(){
	int x = 0, y = 0, dx = 1, dy = 1;
	ll cnt = 0;
	mp1.clear(), mp2.clear();
	while(!cnt || Noc(x, y)){
		if (dx == 1 && dy == 1){
			int tmp = min(n-x, m-y);
			mp1[y-x] = PIP(cnt, PII(0, x));
			cnt += tmp;
			x += tmp, y += tmp;
			if (x == n) dx = -1;
			else dy = -1;
		}
		else if (dx == -1 && dy == 1){
			int tmp = min(x, m-y);
			mp2[x+y] = PIP(cnt, PII(1, x));
			cnt += tmp;
			x -= tmp, y += tmp;
			if (x == 0) dx = 1;
			else dy = -1;
		}
		else if (dx == 1 && dy == -1){
			int tmp = min(n-x, y);
			mp2[x+y] = PIP(cnt, PII(2, x));
			cnt += tmp;
			x += tmp, y -= tmp;
			if (x == n) dx = -1;
			else dy = 1;
		}
		else{
			int tmp = min(x, y);
			mp1[y-x] = PIP(cnt, PII(3, x));
			cnt += tmp;
			x -= tmp, y -= tmp;
			if (x == 0) dx = 1;
			else dy = 1;
		}
	}
	for(int i = 1; i <= Q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = 1ll << 60;
		if (mp1.find(y-x) != mp1.end()){
			PIP Nico = mp1[y-x];
			if (Nico.second.first == 0){
				ans = Nico.first + x - Nico.second.second;
			}
			else{
				ans = Nico.first + Nico.second.second - x;
			}
		}
		
		if (mp2.find(y+x) != mp2.end()){
			PIP Nico = mp2[y+x];
			if (Nico.second.first == 2){
				ans = min(ans, Nico.first + x - Nico.second.second);
			}
			else{
				ans = min(ans, Nico.first + Nico.second.second - x);
			}
		}
		
		if (ans == (1ll << 60))
			puts("-1");
		else
			printf("%lld\n", ans);
		
	}
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}