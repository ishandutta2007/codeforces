#include <stdio.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <memory.h>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#define N 111111
char w[N];
int nxt[26][N];

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	gets(w);
	int n = strlen(w);
	for (int c = 'a'; c <= 'z'; ++c) {
		nxt[c - 'a'][n] = n;
		for (int j = n - 1; j >= 0; --j)
			if (w[j] == c) {
				nxt[c - 'a'][j] = j; 
			} else {
				nxt[c - 'a'][j] = nxt[c - 'a'][j + 1]; 
			}
	}

	int pos = 0;
	while (pos < n) {
		for (int c = 'z'; c >= 'a'; --c) {
			if (nxt[c - 'a'][pos] < n) {
				putchar((char) c);
				pos = nxt[c - 'a'][pos] + 1;
				break;
			}
		}
	}

	cout << endl;

	return 0;
}