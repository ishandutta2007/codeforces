#if 0
2020.06.01

   bitset  O(m/w)  x1, x2 
 a[x1]  a[x2]  a[x2]  a[x1]  a[x] 
 x  bitset  a  1 
   set  a  set  (x1, x2)  x1,
x2  x1, x2 
   set  (x1, x2)  set 
        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#include <set>
#include <bitset>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 2005;
std::bitset<maxn> bs[maxn], pre[maxn];
std::set<par> s1; // (size, id)
std::set<par> s2; // (ans.x1, ans.x2)

int n, m;
bool check (int i, int j) {
	if (i == 0 or j == n + 1) return 0;
	return (bs[i] & bs[j]) != bs[i];
}

void insert (int x) {
	par p(int(bs[x].count()), x);
	s1.insert(p);
	int _x = (-- s1.lower_bound(p)) -> second;
	int x_ = s1.upper_bound(p) -> second;
	s2.erase(par(_x, x_));
	if (check(_x, x)) s2.insert(par(_x, x));
	if (check(x, x_)) s2.insert(par(x, x_));
}

void erase (int x) {
	par p(int(bs[x].count()), x);
	int _x = (-- s1.lower_bound(p)) -> second;
	int x_ = s1.upper_bound(p) -> second;
	s1.erase(p);
	s2.erase(par(_x, x));
	s2.erase(par(x, x_));
	if (check(_x, x_)) s2.insert(par(_x, x_));
}

void print (int x1, int x2) {
	int y1 = int((bs[x1] & ~bs[x2])._Find_first());
	int y2 = int((bs[x2] & ~bs[x1])._Find_first());
	if (x1 > x2) std::swap(x1, x2);
	if (y1 > y2) std::swap(y1, y2);
	printf("%d %d %d %d\n", x1, y1, x2, y2);
}

int main () {
	read(n, m);
	for (int i = 1; i <= m; i ++) {
		pre[i] = pre[i - 1];
		pre[i].set(si(i));
	}

	s1.insert(par(-1, 0));
	s1.insert(par(m + 1, n + 1));
	for (int i = 1; i <= n; i ++)
		insert(i);

	int q = read;
	while (q --) {
		int x = read, l = read, r = read;
		erase(x);
		bs[x] ^= pre[r];
		bs[x] ^= pre[l - 1];
		insert(x);
		if (s2.empty()) puts("-1");
		else print(s2.begin() -> first, s2.begin() -> second);
	}
}