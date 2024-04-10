#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define mk make_pair
#define f first
#define s second

const int Ma = 10000;

map <char, string> name;
map <pair <int, char>, int> a;
int x, p;
char y, t;
int n;

int main(){
//	freopen("in", "r", stdin);
	cin >> name['h'] >> name['a'];
	cin >> n;

	for (int i = 1; i <= n; i++) {
	 	cin >> x >> y >> p >> t;
	 	if (a[mk(p, y)]==2) continue;
	 	if (t=='r'||a[mk(p, y)]) {
	 	 	a[mk(p, y)] = 2;
	 	 	cout << name[y] << " " << p << " " << x << endl;
	 	 	continue;
	 	}
	 	a[mk(p, y)]++;

	}

	return 0;      
}