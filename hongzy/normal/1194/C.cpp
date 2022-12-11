#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 210;

char s[N], t[N], p[N];
int cnt[26], l[3];

int main() {
	int q; scanf("%d", &q);
	while(q --) {
		fill(cnt, cnt + 26, 0);
		scanf("%s%s%s", s + 1, t + 1, p + 1);
		l[0] = strlen(s + 1);
		l[1] = strlen(t + 1);
		l[2] = strlen(p + 1);
		for(int i = 1; i <= l[2]; i ++) cnt[p[i] - 'a'] ++;
		int j = 1;
		for(int i = 1; i <= l[1]; i ++) {
			if(j > l[0] || (s[j] != t[i])) {
				cnt[t[i] - 'a'] --;
			} else j ++;
		}
		bool tag = 1;
		for(int i = 0; i < 26; i ++) {
			if(cnt[i] < 0) {
				tag = 0; break ;
			}
		}
		if(j <= l[0]) tag = 0;
		puts(tag ? "YES" : "NO");
	}	
	return 0;
}