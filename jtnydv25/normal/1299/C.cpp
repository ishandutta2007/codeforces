#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const ll INF = 1e18;

struct Line{
	ll a, b;
    Line(){a = 0, b = -INF;}
	double get(double x){
		return a * x + b;
	}
	Line(ll a, ll b) : a(a), b(b){}
};

typedef long long Long;

// max
struct ConvexHull {
    int size, curr;
    vector<Line> hull;
	double oldx;
    ConvexHull(){size = curr = 0; oldx=-1;}

    ConvexHull(int maxSize) {
        hull.resize(maxSize + 1); size = curr = 0; oldx = -1;
    }

    bool is_bad(int curr, int prev, int next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_Line(Line l) {
        hull[size++] = l;
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    int query(double x) {
		double val = hull[curr].get(x);
		while(curr + 1 < size){
			double nxt = hull[curr + 1].get(x);
			if(nxt > val){
				val = nxt;
				curr++;
			} else break;
		}
        return hull[curr].a;
    }
};

const int N = 1000006;
ll p[N];
int a[N];

// O(N logN)
vector<int> solve(int l, int r){
	if(l > r) return {};
	if(l == r) return {l};
	int mid = (l + r) / 2;
	vector<int> lft = solve(l, mid);
	lft.resize(r - l + 1);
	
	ConvexHull ch(r - mid);
	for(int i = mid + 1; i <= r; i++) ch.add_Line({i, -p[i]});
	int pos = -1, opt = mid, g = -1;
	for(int i = l; i <= mid;){
		int j = lft[i - l];
		double av = (p[j] - p[i - 1]) / (double) (j - i + 1);
		int temp = ch.query(av);
		if( (p[temp] - p[i - 1]) * (j - i + 1) < (p[j] - p[i - 1]) * (temp - i + 1) ){
			pos = i;
			g = j;
			break;
		}
		i = j + 1;
	}
	if(pos != -1){
		for(int i = mid + 1; i <= r; i++) if( (p[i] - p[pos - 1]) * (opt - pos + 1) <= (p[opt] - p[pos - 1]) * (i - pos + 1) ){
			opt = i;

		}
		for(int i = pos; i <= opt; i++) lft[i - l] = opt;
	}
	vector<int> rgt = solve(opt + 1, r);
	copy(all(rgt), lft.begin() + opt - l + 1);
	return lft;
}

int main(){
	int n = 1000000; 
	sd(n);
	for(int i = 1; i <= n; i++){
		a[i] = rand() % 1000000 + 1;
		sd(a[i]);
		p[i] = p[i - 1] + a[i];
	}
	vector<int> ans = solve(1, n);
	for(int i = 1; i <= n;){
		int j = ans[i - 1];
		double val = (p[j] - p[i - 1]) / (double) (j - i + 1);
		for(int k = i; k <= j; k++) printf("%.10lf\n", val);
		i = j + 1;
	}
}