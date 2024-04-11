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

typedef long long ll;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin>> n;
	string s;
	cin>> s;
	int l = 0, r = 2 * n;
	vector<int> pac, star;
	for (int i = 0; i < n; i++){
		if (s[i] == '*')
			star.push_back(i);
		if (s[i] == 'P')
			pac.push_back(i);
	}
	while (l != r){
		int m = (l + r)>> 1;
		int nows = 0;
		int nowp = 0;
		while (nows < star.size() && nowp < pac.size()){
			if (star[nows] < pac[nowp]){
				int ws = nows;
				if (pac[nowp] - star[ws] <= m){
					while (nows < star.size() && star[nows] < pac[nowp])
						nows++;

					while (nows < star.size() && min(pac[nowp] - star[ws] + star[nows] - star[ws], star[nows] - pac[nowp] + star[nows] - star[ws]) <= m)
						nows++;
				}
				nowp++;
			}
			else{
				while (nows < star.size() && star[nows] - pac[nowp] <= m)
					nows++;
				nowp++;
			}
		}
		if (nows == star.size())
			r = m;
		else
			l = m + 1;
	}
	cout << l;
	return 0;
}