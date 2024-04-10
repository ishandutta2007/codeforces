#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define MS0(I) memset(I, 0, sizeof(I));
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define rep(i, n) for(int i = 0; i < n; i ++)
#define rep1(i, a, b) for(int i = a; i < b; i ++)
#define per1(i, a, b) for(int i = a; i >= b; i --)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long LL;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//////////////////////
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const LL  INFF = (LL)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e3 + 7;
bool ck[MXN][MXN];
int main(void){
	int n; scanf("%d", &n);
	int ax, ay; scanf("%d %d", &ax, &ay);
	int sx, sy; scanf("%d %d", &sx, &sy);
	int ex, ey; scanf("%d %d", &ex, &ey);
	queue<PII>Q;
	Q.push( MP(sx, sy) );
	ck[sx][sy] = 1;
	while(!Q.empty()){
		int x, y; tie(x, y) = Q.front(); Q.pop();
		if(x == ex && y == ey){
			puts("YES"); return 0;
		}
		for(int i = -1; i <= 1; ++i)
			for(int j = -1; j <= 1; ++j){
				int nx = x + i;
				int ny = y + j;
				if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
					if(nx == ax || ny == ay) continue;
					if( abs(nx - ax) == abs(ny - ay) ) continue;
					if(!ck[nx][ny]){
						ck[nx][ny] = 1;
						Q.push( MP(nx, ny) );
					}
				}
			}
	}
	puts("NO");
	return 0;
}