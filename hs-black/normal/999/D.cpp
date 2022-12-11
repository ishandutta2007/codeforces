#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
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

ll n, m;
const int N = 200500;
ll a[N], ti;
#include<queue>
queue <int> q[N];
queue <pair <int, ll> > al;
void deal(ll k) {
	for (int o = 1;o <= 2; o++)
	for (int i = 0;i < m; i++) {
		if (q[i].size() > k) {
			for (int j = q[i].size();j > k; j--) {
				int tmp = q[i].front();
				q[i].pop();
				al.push(make_pair(tmp, i));
			}
		}
		else {
			for (int j = q[i].size();j < k; j++) {
				if (al.empty()) break;
				ll dis = i - al.front().second;
				if (dis < 0) dis += m;
				ti += dis;
				a[al.front().first] += dis;
				q[i].push(al.front().first);
				al.pop();
			}
		}
	}
}
int main() {
	n = read(), m = read();
	ll k = n / m;
	for (int i = 1;i <= n; i++) 
	a[i] = read(), q[a[i] % m].push(i);
	deal(k);
	cout << ti << endl;
	for (int i = 1;i <= n; i++) 
	printf ("%lld ", a[i]);
	return 0;
}