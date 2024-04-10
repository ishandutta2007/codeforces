#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 2000
struct pt { int x, y, ind; };
bool comp(const pt&a, const pt&b) { if (a.x / SIZE < b.x / SIZE)return 1; if (a.x / SIZE == b.x / SIZE && a.y<b.y)return 1; return 0; } 
pt p[1000000];
int main() {
	int n,a,b,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d%d", &p[i].x, &p[i].y), p[i].ind = i;
	sort(p, p + n,comp);
	for (i = 0; i < n; i++)printf("%d ", p[i].ind+1);
}