#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	set<char> a;
	a.insert('a'); a.insert('e'); a.insert('i'); a.insert('o'); a.insert('u');
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size()) {
		cout << "No\n"; return 0;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (a.find(s1[i]) == a.end() && a.find(s2[i]) == a.end()) {
			continue;
		}
		if (a.find(s1[i]) != a.end() && a.find(s2[i]) != a.end()) {
			continue;
		}
		cout << "No\n"; return 0;
	}
	cout << "Yes\n";
	//system("pause");
	return 0;
}