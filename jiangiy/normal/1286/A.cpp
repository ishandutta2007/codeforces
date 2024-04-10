#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

int n, s[105];
int main() {
	scanf("%d", & n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", s + i);
	int c[2] ={
		n / 2,(n + 1) / 2}
	;
	for (int i = 1; i <= n; i ++)
		if (s[i])
			c[s[i] & 1] --;
	std::vector < int > u[2];
	int lst =- 1, lp = 0, ans = 0;
	pii st, ed;
	for (int i = 1; i <= n; i ++) {
		if (s[i]) {
			if (lst ==- 1) {
				st = mp(s[i] & 1, i - lp - 1);
			} 
			else if (lst == (s[i] & 1)) {
				u[s[i] & 1].pb(i - lp - 1);
			} 
			else if (lst != (s[i] & 1)) {
				ans ++;
			} 
			lst = s[i] & 1;
			lp = i;
		}
	} 
	ed = mp(lst, n - lp);
	int fans = 1e9;
	for (int x = 0; x < 2; x ++)
		for (int y = 0; y < 2; y ++) {
			int tc[2] ={
				c[0], c[1]}
			, ta = ans;
			if (x & 1)
				tc[st.xx] -= st.yy;
			else ta ++;
			if (y & 1)
				tc[ed.xx] -= ed.yy;
			else ta ++;
			if (tc[0] < 0 || tc[1] < 0)
				continue;
			for (int i = 0; i < 2; i ++) {
				std::sort(u[i].begin(), u[i].end());
				ta += u[i].size() * 2;
				for (int x : u[i])
					if (x <= tc[i])
						tc[i] -= x, ta -= 2;
			} 
			fans = min(fans, ta);
	} 
	printf("%d\n", fans);
}