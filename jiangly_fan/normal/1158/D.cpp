#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 2400;
struct point{
	LL x, y;
	point operator - (const point &b){
		return {x - b.x, y - b.y}; 
	}
}p[maxn];
LL cross(const point &a, const point &b){
	return a.x * b.y - a.y * b.x;
}
char op[maxn];
bool vis[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> p[i].x >> p[i].y;
	cin >> (op + 1);
	int s = 1;
	for(int i = 2; i <= n; i += 1) if(p[i].x < p[s].x) s = i;
	for(int i = 1; i <= n; i += 1){
		cout << s << " ";
		vis[s] = true;
		if(i == n) break;
		int t = 0;
		for(int j = 1; j <= n; j += 1) if(not vis[j])
			if(t == 0) t = j;
			else if((op[i] == 'L') ^ (cross(p[j] - p[s], p[t] - p[s]) < 0)) t = j;
		s = t;
	}
	return 0;
}