#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200000;
struct P{
	LL x, y;
	P operator - (P p){return {x - p.x, y - p.y};}
	LL cross(P p){return x * p.y - y * p.x;}
	LL dis(P p){return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);}
}p[maxn], h[maxn];
LL a[maxn];
double ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int n, hn = 1;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1) p[i].y = p[i - 1].y + a[i], p[i].x = i;
    for(int i = 1; i <= n; i += 1){
        while(hn >= 2 and (h[hn - 1] - h[hn - 2]).cross(p[i] - h[hn - 2]) <= 0) hn -= 1;
        h[hn ++] = p[i];
    }
    for(int i = 1; i < hn; i += 1)
        for(int j = h[i - 1].x + 1; j <= h[i].x; j += 1)
            cout << 1. * (h[i].y - h[i - 1].y) / (h[i].x - h[i - 1].x) << "\n";
    return 0;
}