#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<queue> 
#include<algorithm>
#define ll long long
using namespace std;
const int N = 150050;
priority_queue <pair <ll, int> > q;
ll read(void) {
	ll x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
ll n;

struct node{
	ll pos, val;
	bool operator < (const node &i) const {
		return pos < i.pos;
	}
}ans[N];
int tot;

int main() {
	n = read();
	for (int i = 1;i <= n; i++) {
		int x = read();
		q.push(make_pair(-x, -i));
	}
	while (q.size() >= 2) {
		pair<ll, int> tmp = q.top();
		q.pop();
		pair<ll, int> k = q.top();
		if (k.first == tmp.first) {
			q.pop();
			tmp = make_pair(k.first * 2, min(k.second, tmp.second));
			q.push(tmp);
		}
		else
			ans[++tot] = (node) {-tmp.second, tmp.first};
	}
	pair<ll, int> tmp = q.top();
	ans[++tot] = (node) {-tmp.second, tmp.first};
	sort (ans + 1, ans + tot + 1);
	printf ("%d\n", tot);
	for (int i = 1;i <= tot; i++)
		printf ("%lld ", -ans[i].val);
	return 0;
}