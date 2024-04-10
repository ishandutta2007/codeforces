#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define FOR(a,b,c) for (int c = (a), __for = (b); c < __for; ++c)
#define REP(n) for (int __rep = 0, __for = (n); __rep < __for; ++__rep)

using namespace std;

class event{
public:
	int x;
	int y;
	bool t;
	event(int _x = 0, int _y = 0, bool _t = false) : x(_x), y(_y), t(_t){}
};
bool cmp(event a, event b){
	if (a.x != b.x) return a.x < b.x;
	if (a.t != b.t) return b.t;
	return false;
}

int gr[100005];
int un(int a){if (a == gr[a]) return a; return gr[a] = un(gr[a]);}
void join(int a, int b){gr[un(b)] = un(a);}
int BAD = 100003;

int GET(){
	int a, b, c;
	scanf("%d:%d:%d", &a, &b, &c);
	return c + 60 * (b + 60 * a);
}

int n, m, t;
int in[20005];

vector < event > sweep;

int top(set < int > &S){
	auto it = S.end();
	--it;
	return *it;
}

int main(){
	FOR(0,100005,i) gr[i] = i;
	scanf("%d%d%d", &n, &m, &t);
	FOR(0,n,i) in[i] = GET();
	FOR(0,n,i){
		sweep.push_back(event(in[i], i, false));
		sweep.push_back(event(in[i] + t - 1, i, true));
	}
	sort(sweep.begin(), sweep.end(), cmp);
	
	int R = 0;
	bool GotMax = false;
	set < int > S;
	
	for (auto X : sweep){
		if ((int)S.size() == m) GotMax = true;
		if (X.t){ // erase
			auto it = S.find(X.y);
			if (it != S.end()) S.erase(it);
		}
		else {
			if ((int)S.size() != m){
				++R;
				S.insert(X.y);
			}
			else {
				int a = top(S);
				join(X.y, a);
				S.erase(a);
				S.insert(X.y);
			}
		}
	}
	if (!GotMax) printf("No solution\n");
	else {
		printf("%d\n", R);
		map < int, int > M;
		int CNT = 1;
		FOR(0,n,i){
			int x = un(i);
			if (M[x] == 0) M[x] = CNT++;
			printf("%d\n", M[x]);
		}
	}
	return 0;
}