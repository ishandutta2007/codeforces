#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

string s;

bool one(int x, int y){
	if(x == 0) return y == 0;
	if(x < 0) return one(-x, -y);
	return y % x == 0 && y >= 0;
}

bool ok(int a, int b, int c, int d){
	if(!a && b) return 0;
	if(!c && d) return 0;
	if(!a && !b) return one(c, d);
	if(!c && !d) return one(a, b);
	if(a < 0) return ok(-a, -b, c, d);
	if(c < 0) return ok(a, b, -c, -d);
	return b % a == 0 && d % c == 0 && b >= 0 && b / a == d / c;
}

int main(){
	int a, b;
	cin >> a >> b >> s;
	int dx = 0, dy = 0;
	for(auto &i : s){
		if(i == 'R') dx++;
		if(i == 'U') dy++;
		if(i == 'L') dx--;
		if(i == 'D') dy--;
	}
	int px = 0, py = 0;
	for(auto &i : s){
		if(ok(dx, a-px, dy, b-py)){
			puts("Yes");
			return 0;
		}
		if(i == 'R') px++;
		if(i == 'U') py++;
		if(i == 'L') px--;
		if(i == 'D') py--;
	}
	puts("No");
}