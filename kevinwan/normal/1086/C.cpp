#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
char t[200];
bool use[200];
string mi,ma,s,a,b;
int n,k;
bool suc = 0;
void solve(string &s,string &a,string &b,int i) {
	if (i == n) { suc = 1; return; }
	if (t[s[i]]) {
		if (a[i] < t[s[i]] && t[s[i]] < b[i]) { suc = 1; return; }
		else if (t[s[i]]<a[i] || t[s[i]]>b[i])return;
		else if (t[s[i]] == a[i] && a[i] == b[i])solve(s, a, b, i + 1);
		else if (t[s[i]] == a[i])solve(s, a, ma,i+1);
		else if (t[s[i]] == b[i])solve(s, mi, b, i + 1);
	}
	else {
		int j;
		for (j = a[i] + 1; j <= min(b[i] - 1,'a'+k-1); j++)if (!use[j]) {
			t[s[i]] = j;
			use[j] = 1;
			suc = 1;
			return;
		}
		if (a[i] == b[i]) {
			if (use[a[i]])return;
			t[s[i]] = a[i];
			use[a[i]] = 1;
			solve(s, a, b, i + 1);
			return;
		}
		char t2[200];
		bool use2[200];
		memcpy(t2, t, sizeof(t));
		memcpy(use2, use, sizeof(use));
		if (!use[a[i]]&&a[i]>='a') {
			use[a[i]] = 1;
			t[s[i]] = a[i];
			solve(s, a, ma, i + 1);
		}
		if (suc)return;
		if(!use[b[i]]&&b[i]<='z'){
			memcpy(t, t2, sizeof(t));
			memcpy(use, use2, sizeof(use2));
			t[s[i]] = b[i];
			use[b[i]] = 1;
			solve(s, mi, b, i + 1);
		}
		if(!suc){
		memcpy(t, t2, sizeof(t));
		memcpy(use, use2, sizeof(use2));
		}
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < 1000000; i++)mi.push_back('a'-1), ma.push_back('z'+1);
	while (tc--) {
		suc = 0;
		memset(t, 0, sizeof(t));
		memset(use, 0, sizeof(use));
		cin >> k >>s>> a >> b;
		n = a.size();
		solve(s,a,b,0);
		if (!suc)printf("NO\n");
		else {
			printf("YES\n");
			char cur = 'a';
			for (int i = 'a'; i <'a'+k; i++) {
				if (t[i])printf("%c", t[i]);
				else {
					while (use[cur])cur++;
					use[cur] = 1;
					printf("%c", cur);
				}
			}
			printf("\n");
		}
	}
	getchar(); getchar();
}