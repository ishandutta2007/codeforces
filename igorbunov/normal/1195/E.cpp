#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

vector< int > B, C;

void build(const vector<int> A, int k) {
	int n = A.size();
	B.resize(n);
	C.resize(n);
	//k--;

	for(int i = 0; i < n; i++)
	{
		if(i % k)
			B[i] = min(A[i], B[i - 1]);
		else
			B[i] = A[i];
	}

	C.back() = A.back();
	for(int i = n - 2; i >= 0; i--)
	{
		if((i + 1) % k)
			C[i] = min(A[i], C[i + 1]);
		else
			C[i] = A[i];
	}
}

int GetMin(int l, int k) {
	return min(C[l], B[l + k - 1]);
}

signed main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	int a, b;
	cin >> a >> b;
	vector<int> g(1000000);
	int x, y, z;
	cin >> arr[0][0] >> x >> y >> z;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j == 0) {
				continue;
			}

			if (j == 0) {
				arr[i][j] = (arr[i - 1].back() * x + y) % z;
			} else {
				arr[i][j] = (arr[i][j - 1] * x + y) % z;
			}
			//cout << arr[i][j] << " ";
		}
	}

	vector<vector<int>> b1(m - b + 1, vector<int>(n));
	for (int i = 0; i < n; i++) {
		build(arr[i], b);
		//return 0;
		for (int j = 0; j < m - b + 1; j++) {
			b1[j][i] = GetMin(j, b);
		}
	}

	//return 0;
	int ans = 0;

	for (int i = 0; i < m - b + 1; i++) {
		build(b1[i], a);

		for (int j = 0; j < n - a + 1; j++) {
			ans += GetMin(j, a);
		}
	}

	cout << ans;
}