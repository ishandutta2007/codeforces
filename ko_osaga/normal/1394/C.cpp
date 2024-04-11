#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 500005;

vector<pi> v;
pi ans;
bool trial(int T){
	int sx = 0, ex = 1e9;
	int sy = 0, ey = 1e9;
	int sa = -1e9, ea = 1e9;
	for(auto &[x, y] : v){
		sx = max(sx, x - T);
		ex = min(ex, x + T);
		sy = max(sy, y - T);
		ey = min(ey, y + T);
		sa = max(sa, x - y - T);
		ea = min(ea, x - y + T);
	}
	for(int i=sx; i<=ex; i++){
		int t = max(sy, i - ea), u = min(ey, i - sa);
		if(i == 0) t = max(t, 1);
		if(t <= u){
			ans = pi(i, t);
			return 1;
		}
	}
	return 0;
}

char buf[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		int l = strlen(buf);
		int x = count(buf, buf + l, 'B');
		int y = count(buf, buf + l, 'N');
		v.emplace_back(x, y);
	}
	int s = 0, e = 1e6;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m + 1;
	}
	trial(s);
	cout << s << endl;
	for(int i=0; i<ans.first; i++) putchar('B');
	for(int i=0; i<ans.second; i++) putchar('N');
	puts("");
}