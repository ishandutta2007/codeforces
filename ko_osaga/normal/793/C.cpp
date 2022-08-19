#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
#define y1 sexsexsex
const int mod = 1e9 + 7;
const int MAXN = 500005;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int x1, y1, x2, y2;

bool cmp(pi a, pi b){
	if(a.second < 0) a.second *= -1, a.first *= -1;
	if(b.second < 0) b.second *= -1, b.first *= -1;
	return a.first * b.second < b.first * a.second;
}

int main(){
	int n;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	pi st(0, 1);
	pi ed(10000000, 1);
	for(int i=0; i<n; i++){
		int rx, ry, vx, vy;
		scanf("%d %d %d %d",&rx,&ry,&vx,&vy);
		if(vx == 0 && (rx <= x1 || rx >= x2)){
			puts("-1");
			return 0;
		}
		if(vy == 0 && (ry <= y1 || ry >= y2)){
			puts("-1");
			return 0;
		}
		if(vx != 0){
			pi xs = pi(x1 - rx,vx);
			pi xe = pi(x2 - rx,vx);
			if(cmp(xe, xs)) swap(xs, xe);
			st = max(st, xs, cmp);
			ed = min(ed, xe, cmp);
		}
		if(vy != 0){
			pi ys = pi(y1 - ry, vy);
			pi ye = pi(y2 - ry, vy);
			if(cmp(ye, ys)) swap(ye, ys);
			st = max(st, ys, cmp);
			ed = min(ed, ye, cmp);
		}
	}
	if(cmp(st, ed)){
		printf("%.10f\n", 1.0 * st.first / st.second);
	}
	else{
		puts("-1");
	}
}