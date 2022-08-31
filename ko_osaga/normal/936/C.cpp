#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 2005;

int n, p[MAXN];
vector<int> ans;

void Haja(int x){
	x = n - x;
	rotate(p, p + n - x, p + n);
	reverse(p, p + x);
	ans.push_back(x);
}

void solve(){
	int csorted = (n / 2) * 2;
	bool rev = 0;
	while(csorted >= 2){
		int x, y;
		if(csorted == n){
			x = 0, y = 1;
		}
		else{
			x = p[csorted];
			y = p[n - 1];
			if(!rev) x--, y++;
			else x++, y--;
		}
		x = (x + n) % n;
		y = (y + n) % n;
		int px = find(p, p + n, x) - p;
		Haja(px + 1);
		Haja(0);
		Haja(csorted);
		int py = find(p, p + n, y) - p;
		Haja(py);
		int pxx = find(p, p + n, x) - p;
		Haja(pxx + 1);
		rev ^= 1;
		csorted -= 2;
	}
	if(n > 1){
		int pos = find(p, p + n, 0) - p;
		if(p[(pos + 1) % n] == n - 1){
			Haja(0);
		}
		pos = find(p, p + n, 0) - p;
		Haja(pos);
		Haja(n - pos);
		Haja(0);
	}
}

int main(){
	string s, t;
	cin >> n >> s >> t;
	vector<int> r1(n), r2(n);
	iota(r1.begin(), r1.end(), 0);
	iota(r2.begin(), r2.end(), 0);
	sort(r1.begin(), r1.end(), [&](int x, int y){
		return s[x] < s[y];
	});
	sort(r2.begin(), r2.end(), [&](int x, int y){
		return t[x] < t[y];
	});
	for(int i=0; i<n; i++){
		if(s[r1[i]] != t[r2[i]]){
			puts("-1");
			return 0;
		}
		p[r1[i]] = r2[i];
	}
	solve();
	cout << ans.size() << endl;
	for(auto &i : ans) printf("%d ", i);
}