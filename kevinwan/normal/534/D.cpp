#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> id[200000];
int num[200000], at[200000];
vector<int> v;
multiset<int> s[3];
int main() {
	int n, i, x;
	scanf("%d", &n);
	int big = -1;
	for (i = 0; i < n; i++)scanf("%d", &x), num[x]++, id[x].push_back(i + 1), big = max(big, x);
	for (i = 0; i <= big; i++)num[i]--,v.push_back(i);
	for (i = 0; i < 200000; i++)for (int j = 0; j < num[i]; j++)s[i % 3].insert(i);
	for (i = 0; i < 200000; i++)if (num[i] < 0) { printf("Impossible"); return 0; }
	i = big+1;
	set<int>::iterator it;
	while (1) {
		if (s[i % 3].size() == 0)break;
		if (*(s[i % 3].begin()) > i)break;
		i = *(it=(--s[i % 3].upper_bound(i)));
		num[i]--;
		v.push_back(i);
		s[i % 3].erase(it);
		i++;
	}
	if (v.size() != n)printf("Impossible");
	else {
		printf("Possible\n");
		for (int x : v)printf("%d ", id[x][at[x]++]);
	}
}