#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100005;
int f[N], a[N], n;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
struct node {
	int x, pos;
	bool operator <(const node &i) const{
		return x < i.x;
	}
}s[N];
int siz[N], cnt, num, res;
int ansk, anscnt; 
int v[N];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge(int x,int y) {
	int fx = find(x), fy = find(y);
	if (siz[fx] > siz[fy]) {
		swap(fx, fy);
		swap(x, y);
	}
	siz[fy] += siz[fx];
	cnt--;
	if (siz[fy] > num) num = siz[fy], res = 1;
	else if (siz[fy] == num) res++;
	f[fx] = fy;
}

int main() {
	n = read();
	for (int i = 1;i <= n; i++)
		s[i].x = a[i] = read(), f[i] = s[i].pos = i;
	sort(s + 1, s + n + 1);
	int x = 0;
	for (int i = 1;i <= n; ) {
		x = s[i].x;
		while (s[i].x == x) {
			cnt++;
			int p = s[i].pos;
			v[p] = 1;
			siz[p] = 1;
			if (1 > num) num = 1, res = 1;
			else if (1 == num) res++;
			if (v[p-1]) merge(p-1, p);
			if (v[p+1]) merge(p+1, p);
			i++;
		}
		if (res == cnt) {
			if (cnt > anscnt) {
				anscnt = cnt;
				ansk = s[i-1].x+1;
			}
		}
	}
	cout << ansk << endl;
	return 0;
}