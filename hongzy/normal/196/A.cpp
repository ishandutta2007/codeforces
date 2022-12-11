#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
char s[N];
int n;
vector<int> v[26];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		v[s[i] - 'a'].push_back(i);
	}
	int r = 0;
	for(int i = 25; i >= 0; i --) {
		for(int x : v[i]) {
			if(x > r) {
				putchar(i + 'a');
				r = x;
			}
		}
	}
	return 0;
}