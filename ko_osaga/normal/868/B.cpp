#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 1000005;
typedef long long lint;

bool btw(int s, int x, int e){
	return s < x && x < e;
}

int main(){
	int p1, p2;
	int h, m, s;
	cin >> h >> m >> s >> p1 >> p2;
	if(p1 == 12) p1 = 0;
	if(p2 == 12) p2 = 0;
	if(h == 12) h = 0;
	if(p1 > p2) swap(p1, p2);
	bool uproad = 1;
	bool dnroad = 1;
	if(btw(5 * p1, s, 5 * p2)) uproad = 0;
	else dnroad = 0;
	if(btw(10 * p1, 2 * m + 1, 10 * p2)) uproad = 0;
	else dnroad = 0;
	if(btw(2 * p1, 2 * h + 1, 2 * p2)) uproad = 0;
	else dnroad = 0;
	if(uproad == 0 && dnroad == 0){
		cout << "NO";
		return 0;
	}
	else cout << "YES";
}