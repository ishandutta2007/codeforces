#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int read(void) {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c=getchar();
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}

priority_queue<int> q;
int T, n, pre;
long long ans;

int main() {
	T = read();
	while (T--) {
		n = read(), ans = pre = 0;
		for (int i = 1;i <= n; i++) q.push(read());
		while (q.size()) {
			int x = q.top(); q.pop();
			if (x == pre || x & 1) continue;
			pre = x, x >>= 1, ans++;
			q.push(x);
		}
		cout << ans << endl;
	}
	return 0;
}