#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()


int mas[111];

string getname(int val) {
	string res;
	res += val % 26 + 'A';
	val /= 26;
	res += val % 26 + 'a';
	return res;
}


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int k, n;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for(int i = 0; i < k - 1; i++) mas[i] = cnt++;
	for(int i = k - 1; i < n; i++) {
		string s;
		cin >> s;
		if (s == "YES") mas[i] = cnt++;
		else mas[i] = mas[i-k+1];
	}
	for(int i = 0; i < n; i++) {
		cout << getname(mas[i]) << " ";
	}

	return 0;
}