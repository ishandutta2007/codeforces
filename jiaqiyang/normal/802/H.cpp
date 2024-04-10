#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second
int n;
string s1 = "", s2 = "";

void oper(int x) { //a[x] += a[x - 1]
	s1 = s1 + char('a' + x - 1);
}

int main() {
	cin >>n; 
	rep(i,1,18) s2 = s2 + char('a' + i - 1);
	rep(j,0,17) {
		if (!j) rep(i,1,17) oper(i); else dep(i,17,j) oper(i);
		if (n >> j & 1) oper(18);
	}
	oper(17), oper(17);
	if (n >> 18 & 1) oper(18);
	if (n >> 19 & 1) oper(18), oper(18);
	cout <<s1<<' '<<s2<<endl;
	return 0;
}