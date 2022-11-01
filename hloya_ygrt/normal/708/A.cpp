#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <vector>
using namespace std;

template <typename T>
T next_int() {
	T x = 0, p = 1;
	char ch;
	do { ch = getchar(); } while(ch <= ' ') ;
	if(ch == '-') {
		p = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return p * x;
}

const int max_int = (int)1e9 + 227 + 1;
const int max_n = (int)1e6 + 227 + 1;
const int mod = (int)1e9 + 7;

int main() {
//	freopen(".in", "r", stdin);

	string a; cin >> a;

	bool ok = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != 'a') {
			a[i]--; i++;
			while(i < a.size() && a[i] != 'a') a[i]--, i++;
			ok = 1;
			break;
		} 
	}

	if(!ok) a[a.size() - 1] = 'z';

	cout << a << "\n";
}