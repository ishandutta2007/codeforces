#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
#define list Sex


struct point{
	int x, y, c;
	bool operator <(const point &t) const{ return y < t.y; }
}P[2020];
 
int N, K;
int xcnt, X[2020];
multiset<int> list[2020];
map<int, int> points;
 
struct intv{
	intv(int s_, int e_){
		s = s_; e = e_;
		l = X[e] - X[s];
	}
	int s, e, l;
	bool operator <(const intv &t) const{
		return l > t.l;
	}
};

lint func(pi x, pi y){
	return 1ll * (X[y.second] - X[x.second]) * (X[y.first] + 1);
}

priority_queue<intv> Q;
lint area;
void InitArea(){ area = 0; }
lint GetArea(){ 
	lint kek = 0;
	if(sz(points)){
		pi p = *points.begin();
		int x, y; tie(x, y) = p;
		kek += 1ll * (X[y] - 0) * (X[x] + 1);
	}
	return area + kek;
	/*
	area = 0;
	int prev = 0;
	for(auto &[x, y] : points){
		area += 1ll * (X[y] - prev) * (X[x] + 1);
		prev = X[y];
	}

	return area;*/
	}

void INSERT(int x, int y){
	auto itr = points.lower_bound(x);
	if(itr != points.begin() && itr != points.end()){
		area -= func(*prev(itr), *itr);
	}
	points[x] = y;
	itr = points.lower_bound(x);
	if(itr != points.begin()) area += func(*prev(itr), *itr);
	if(next(itr) != points.end()) area += func(*itr, *next(itr));
}

void addpoint(int x, int y)
{
	auto J = points.upper_bound(x);
	if (J != points.begin()){
		J--;
		if (J->second >= y) return;
	}
 
	auto I = points.lower_bound(x);
	while (I != points.end() && I->second <= y){
		{
			if(I != points.begin()) area -= func(*prev(I), *I);
			if(next(I) != points.end()) area -= func(*I, *next(I));
			if(I != points.begin() && next(I) != points.end()) area += func(*prev(I), *next(I));
		}
		I = points.erase(I);
	}

	INSERT(x, y);
	points[x] = y;
 
	auto A = points.lower_bound(x);
	if (A != points.begin()){
		auto B = A; B--;
		Q.push(intv(A->first, B->second));
	}
	auto C = A; C++;
	if (C != points.end()){
		Q.push(intv(C->first, A->second));
	}
}
 
int L;

int gap(int x){
	if(x == -1) return P[0].y + 1;
	if(x == N - 1) return L - P[N - 1].y;
	return P[x + 1].y - P[x].y;
}

int main()
{
	scanf ("%d %d %d",&N,&K,&L);
	for (int i=0;i<N;i++){
		int x,y,c; scanf ("%d %d %d",&x,&y,&c);
		P[i] = {x,y,c};
	}
	lint ret = 0;
 
	sort(P, P+N, [](const point &a, const point &b){return a.x < b.x;});
	int lx = 0x80000000;
	for (int i=0;i<N;i++){
		if (lx != P[i].x){
			lx = P[i].x;
			X[++xcnt] = lx;
		}
		P[i].x = xcnt;
	}
	X[0] = -1;
	X[xcnt + 1] = L;
	sort(P, P+N);
 
	for (int s=0;s<N;s++) if (s == 0 || (P[s-1].y != P[s].y)){
		for (int i=1;i<=K;i++) list[i].clear();
		for (int t=s;t<N;t++) list[P[t].c].insert(P[t].x);
 
		bool good = true;
		for (int i=1;i<=K;i++) if (list[i].empty()) good = false;
 
		if (!good) continue;

		InitArea();
		points.clear();
		while (!Q.empty()) Q.pop();
		for (int i=1;i<=K;i++){
			list[i].insert(0);
			list[i].insert(xcnt+1);
			int last = -1;
			for (int x : list[i]){
				if (x){
					addpoint(last, x);
				}
				last = x;
			}
		}

		for (int t=N-1;t>=s;t--){
			while (!Q.empty()){
				int x = Q.top().s, y = Q.top().e, l = Q.top().l;

				if (x == 0 || y == xcnt+1 || !points.count(x)){
					Q.pop();
					continue;
				}

				auto I = points.lower_bound(x); I--;
				if (I->second != y){
					Q.pop();
					continue;
				}
				break;
			}

			if(gap(t) > 0){
				lint QQ = 1ll * gap(t) * gap(s - 1);
				int prev = 0;
				lint area = GetArea();
				ret += (QQ % mod) * (area % mod);
				ret %= mod;
			}
			multiset<int> &l = list[P[t].c];
			auto I = l.lower_bound(P[t].x);
			auto J = I; J--;
			auto K = I; K++;
			l.erase(I);
			addpoint(*J, *K);

		}
	}

printf("%lld\n", ret);
	return 0;
}