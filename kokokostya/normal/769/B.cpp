#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <stack>
#include <complex>

using namespace std;

int main() {
	//freopen("integral.in", "r", stdin);
	//freopen("integral.out", "w", stdout);
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	int zero = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		if (!a[i])
			zero++;
	}
	if (a[0] == 0 || sum < n - 1){
		cout << -1;
		return 0;
	}
	cout << n - 1 << '\n';
	vector<bool> used(n);
	used[0] = 1;
	for (int i = 0; i < n - 1 - zero; i++){
		for (int j = 0; j < n; j++){
			if (used[j] && a[j]){
				for (int q = 0; q < n; q++){
					if (!used[q] && a[q]){
						cout << j + 1 << ' ' << q + 1 << '\n';
						a[j]--;
						used[q] = 1;
						j = n;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < zero; i++){
		for (int j = 0; j < n; j++){
			if (used[j] && a[j]){
				for (int q = 0; q < n; q++){
					if (!used[q]){
						cout << j + 1 << ' ' << q + 1 << '\n';
						a[j]--;
						used[q] = 1;
						j = n;
						break;
					}
				}
			}
		}
	}


	return 0;
}