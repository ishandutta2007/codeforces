#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define mod 1000000007ll
using namespace std;
//up to 2^29
char c;
int n, timer = 0, t,cnt[5000007];
int bintree[5000007][2];

void add(int t, int v = 0, int p = 29) {
	if(p == -1) {
		cnt[v]++;
		return;
	}
	if(bintree[v][(t>>p)&1] == 0)
		bintree[v][(t>>p)&1] = ++timer;
	add(t, bintree[v][(t>>p)&1], p-1);
}
bool del(int t, int v = 0, int p = 29) {
	if(p == -1) {
		cnt[v]--;
		return cnt[v] == 0;
	}
	if(del(t, bintree[v][(t>>p)&1], p-1)) {
		 bintree[v][(t>>p)&1] = 0;
	}
	return !(bintree[v][1]|bintree[v][0]);
}

int query(int t, int v = 0, int p = 29) {
	if(p == -1)
		return t;
	int des = ((t>>p)&1)^1;
	if(bintree[v][des]) {
		t ^= (1<<p)*des;
		query(t, bintree[v][des], p-1);
	} else {
		t ^= (1<<p)*(1^des);
		query(t, bintree[v][1^des], p-1);
	}
}

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("\n%c", &c);
		scanf("%d", &t);
		if(c == '+')
			add(t);
		else if(c == '-')
			del(t);
		else
			cout << max(t, query(t)) << "\n";
	}
}