#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};


int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set< pair<int, int> > q;
	vector< vector<int> > ans;
	for (int i = 0; i < n; i++){
		auto j = q.upper_bound({ -a[i], 0 });
		if (j != q.end()){
			ans[(*j).second].push_back(a[i]);
			q.insert({ -a[i], (*j).second });
			q.erase(j);
		}
		else{
			int sz = ans.size();
			ans.push_back({ a[i] });
			q.insert({ -a[i],sz });
		}
	
	}
	for (int i = 0; i < ans.size(); i++){
		for (int j : ans[i])
			cout << j << ' ';
		cout << '\n';
	}
		
	return 0;
}