#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
 
#define mp make_pair
 
typedef double db;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
 
struct Node {
	int a, b;
	bool operator < (const Node &o) const {
		//y = (1 / bi) x + 1 / ai
		if(b == o.b) return a > o.a;
		return b < o.b;
	}
	db ins(Node o) {
		return ((db) a * b * o.b - (db) b * o.a * o.b) / ((db) o.a * o.b * a - (db) a * b * o.a);
	}
} t[N], dt[N];
int n, st[N];
map<pii, bool> Map;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &t[i].a, &t[i].b);
		dt[i] = t[i];
	}
	sort(t + 1, t + n + 1);
	int top = 0;
	for(int i = 1; i <= n; i ++) {
		if(i > 1 && t[i - 1].b == t[i].b) continue ;
		while(top > 1 && t[st[top - 1]].ins(t[st[top]]) - t[st[top]].ins(t[i]) > 1e-20) top --;
		st[++ top] = i;
	}
	for(int i = 1; i <= top; i ++) if(top == i || t[st[i + 1]].ins(t[st[i]]) > 1e-20) Map[mp(t[st[i]].a, t[st[i]].b)] = 1;
	for(int i = 1; i <= n; i ++) if(Map[mp(dt[i].a, dt[i].b)]) printf("%d ", i);
	return 0;
}
/*
1/ai + B/bi = T is min
y = kx + b(x >= 0)lowest
y = 1 / 3000 x + 1 / 1000
y = 1 / 1500 x + 1 / 1500
y = 1 / 1000 x + 1 / 3000

*/