#pragma comment (linker, "/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef room210
	freopen("in.txt", "r", stdin);
	clock_t start = clock();
#else
	//freopen("circles.in", "r", stdin);
	//freopen("circles.out", "w", stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

#ifdef room210
	cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}

#define double ld

double eps = 1e-7;

struct treap{
	typedef struct _node{
		double key; int prior;
		int val;
		int mx;
		_node* l;
		_node* r;
		_node(double key, int val):key(key), val(val) { prior = (rand() << 16) | rand(); mx = val; l = 0; r = 0; }
		void recalc(){
			mx = max(val, max(Mx(l), Mx(r)));
		}
		static int Mx (_node* v){
			if (!v)
				return 0;
			return v->mx;
		}
	}*node;

	node root;
	treap(){ root = 0; }

	node merge (node l, node r){
		if (l == 0)
			return r;
		if (r == 0)
			return l;
		if (l->prior < r->prior){
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else{
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	void split (node v, double key, node& l, node& r){
		l = r = 0;
		if (v == 0)
			return;
		if (v->key + eps < key){
			l = v;
			split(l->r, key, l->r, r);
			l->recalc();
		}
		else{
			r = v;
			split(r->l, key, l, r->l);
			r->recalc();
		}
	}

	void add (double key, int val){
		node l, r;
		split(root, key, l, r);
		root = merge( merge(l, new _node(key, val)), r );
	}

	int Max (double key){
		node l, r;
		split(root, key, l, r);
		int ans = ((r == 0) ? 0 : r->mx);
		root = merge(l, r);
		return ans;
	}
};

int n;
double a1, a2;
double phi;

struct Point{
	double x, y;
	Point() {}
	Point (double x, double y):x(x),y(y) {}
	void scan() { cin >> x >> y; }
	Point rotate (double a){
		return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
	void print(){
		cout<<x<<' '<<y<<endl;
	}
};

Point points[100500];
double intersects[100500];
int p[100500];

bool cmp (int q, int w){
	if (intersects[w] + eps < intersects[q])
		return true;
	if (intersects[q] + eps < intersects[w])
		return false;
	return points[q].y < points[w].y;
}

void solve() {
	treap tree;
	cin>>n;
	int b1, b2;
	scanf("%d/%d", &b1, &b2);
	a1 = atan2(1.0 * b1, 1.0 * b2);
	scanf("%d/%d", &b1, &b2);
	a2 = atan2(1.0 * b1, 1.0 * b2);
	//printf ("%.10lf %.10lf\n", a1, a2);
	phi = a2 - a1;
	for (int i = 0; i < n; ++i){
		points[i].scan();
		points[i] = points[i].rotate(-a1);
		//points[i].print();
	}
	for (int i = 0; i < n; ++i){
		intersects[i] = points[i].x - (points[i].y / tan(phi));
		//cout<<intersects[i]<<' ';
	}
	//cout<<endl;
	for (int i = 0; i < n; ++i)
		p[i] = i;
	sort(p, p + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int cur = p[i];
		//points[cur].print();
		if (intersects[cur] < eps){
			break;
		}
		if (points[cur].y < eps)
			continue;
		int res = tree.Max(points[cur].y + 1e-6) + 1;
		if (ans < res){
			ans = res;
			//Point now = points[cur].rotate(a1);
			//now.print();
		}
		tree.add(points[cur].y, res);
	}
	cout<<ans;
}