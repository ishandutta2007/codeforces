#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 610000;
const int inf = 1000000007;
const int mod = 1000000007;


int n;
vector<int> a[10001];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		int x;
		//cin >> x;
		scanf("%d", &x);
		a[x].push_back(i);
	}

	for (int i = 1; i <= 5000; i++)
		if (a[i].size() % 2 == 1) {
			cout << -1;
			return 0;
		}

	for (int i = 1; i <= 5000; i++)
		for (int j = 0; j < a[i].size(); j += 2) 
			//cout << a[i][j] << " " << a[i][j + 1] << endl;
			printf("%d %d\n", a[i][j], a[i][j + 1]);

	return 0;
}