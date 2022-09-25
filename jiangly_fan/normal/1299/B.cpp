#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
struct P{
	LL x, y;
	P operator - (P p){return {x - p.x, y - p.y};}
	LL cross(P p){return x * p.y - y * p.x;}
	LL dis(P p){return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);}
}p[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> p[i].x >> p[i].y;
	if(n % 2) no();
	for(int i = 0; i < n / 2; i += 1){
		if((p[i + 1] - p[i]).cross(p[i + n / 2] - p[(i + n / 2 + 1) % n])) no();
		if(p[i].dis(p[i + 1]) != p[i + n / 2].dis(p[(i + n / 2 + 1) % n])) no();
	}
	cout << "YES";
    return 0;
}