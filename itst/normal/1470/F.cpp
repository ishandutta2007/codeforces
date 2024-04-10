#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define int long long
const int _ = 2e5 + 7; int T , N;
struct vec{
	int x , y; vec(int _x = 0 , int _y = 0) : x(_x) , y(_y){}
	friend vec operator +(vec p , vec q){return vec(p.x + q.x , p.y + q.y);}
	friend vec operator -(vec p , vec q){return vec(p.x - q.x , p.y - q.y);}
	friend int operator *(vec p , vec q){return p.x * q.x + p.y * q.y;}
	friend int operator %(vec p , vec q){return p.x * q.y - p.y * q.x;}
	friend bool operator <(vec p , vec q){return p.x < q.x || p.x == q.x && p.y < q.y;}
}nd[_];

struct hull{
	vec s[_] , mdf[_] , seq[_]; int top , cnt , pt[_]; void clear(){top = cnt = 0;}
	void push(vec A , int d){
		seq[++cnt] = A; pt[cnt] = top;
		while(top >= 2 && (s[top] - A) % (s[top - 1] - A) * d >= 0) --top;
		mdf[cnt] = s[++top]; s[top] = A;
	}
	bool pop(){if(!cnt){return 0;} s[top] = mdf[cnt]; top = pt[cnt--]; return 1;}
	int qry(vec v){
		if(!top){return 4e18;} int L = 1 , R = top; while(L < R){int M = (L + R) >> 1; s[M] * v <= s[M + 1] * v ? R = M : L = M + 1;} return s[L] * v;
	}
};
struct dequehull{
	hull pre , suf;
	void clear(){pre.clear(); suf.clear();}
	void push_front(vec r){pre.push(r , -1);}
	void push_back(vec r){suf.push(r , 1);}
	bool rebuild(bool flg){
		vector < vec > pot;
		for(int i = pre.cnt ; i ; --i) pot.push_back(pre.seq[i]);
		for(int i = 1 ; i <= suf.cnt ; ++i) pot.push_back(suf.seq[i]);
		pre.clear(); suf.clear(); int sz = (pot.size() + flg) / 2;
		for(int i = sz - 1 ; ~i ; --i) push_front(pot[i]);
		for(int i = sz; i < pot.size() ; ++i) push_back(pot[i]);
		return pot.size();
	}
	void pop_front(){if(!pre.pop() && rebuild(1)) pre.pop();}
	void pop_back(){if(!suf.pop() && rebuild(0)) suf.pop();}
	int qry(vec v){return min(pre.qry(v) , suf.qry(v));}
}h1 , h2;

int ans , tp[_];
void w1(){
	int mn = 1e9 , mx = -1e9; sort(nd + 1 , nd + N + 1);
	for(int i = 1 ; i <= N ; ++i) tp[i] = ((mx = max(mx , nd[i].y)) - (mn = min(mn , nd[i].y))) * (nd[i].x - nd[1].x);
	mn = 1e9; mx = -1e9; for(int i = N ; i ; --i) ans = min(ans , tp[i - 1] + ((mx = max(mx , nd[i].y)) - (mn = min(mn , nd[i].y))) * (nd[N].x - nd[i].x));
}

int ly[_] , u[_] , l[_] , L , H;
void w2(){
	sort(nd + 1 , nd + N + 1); L = nd[N].x - nd[1].x; for(int i = 1 ; i <= N ; ++i){ly[i] = nd[i].y;}
	sort(ly + 1 , ly + N + 1); H = ly[N] - ly[1]; ly[0] = ly[1];
	for(int i = 1 ; i <= N ; ++i){u[i] = ly[i - 1]; l[i] = nd[N].x;}
	ly[0] = -2e9; for(int i = N ; i ; --i){int p = upper_bound(ly + 1 , ly + N + 1 , nd[i].y) - ly; l[p] = nd[i].x;}
	for(int i = 2 ; i <= N ; ++i) l[i] = min(l[i] , l[i - 1]);
	
	int p1 = 1 , p2 = 1; h1.clear(); h2.clear();
	for(int i = N ; i ; --i) h1.push_back(vec(ly[N] - ly[i] , (u[i] - ly[1]) * (nd[N].x - l[i])));
	for(int i = N - 1 ; i ; --i){
		while(p1 <= N && l[p1] > nd[i].x) if(p2 == p1){h1.pop_back(); ++p2; ++p1;} else{h2.pop_front(); ++p1;}
		while(p2 <= N && ly[p2] <= nd[i + 1].y){h1.pop_back(); h2.push_back(vec(nd[N].x - l[p2] , ly[N] - ly[p2])); ++p2;}
		ans = min(ans , min(h1.qry(vec(nd[i].x - nd[1].x , 1)) , h2.qry(vec(ly[p2 - 1] - ly[1] , nd[i].x - nd[1].x))));
	}
}

void w3(){
	u[N] = l[N] = nd[N].y; for(int i = N - 1 ; i ; --i){u[i] = min(u[i + 1] , nd[i + 1].y); l[i] = max(l[i + 1] , nd[i + 1].y);}
	h1.clear(); h2.clear(); for(int i = 1 ; i <= N ; ++i) h1.push_back(vec(nd[i].x , (l[i] - u[i])));
	int p1 = N , p2 = N , up = -1e9 , dwn = 1e9;
	for(int i = 1 ; i < N ; ++i){
		up = max(up , nd[i].y); dwn = min(dwn , nd[i].y);
		while(p1 >= i && u[p1] > nd[i].y){if(p1 > p2) h2.pop_back(); else{h1.pop_back(); h2.push_front(vec(nd[p1].x , l[p1]));} --p1;}
		while(p2 >= i && l[p2] < nd[i].y){if(p1 < p2) h2.pop_back(); else{h1.pop_back(); h2.push_front(vec(nd[p2].x , -u[p2]));} --p2;}
		if(min(p1 , p2) >= i) h1.pop_front(); else if(max(p1 , p2) >= i) h2.pop_front();
		p1 += p1 < i; p2 += p2 < i;
		
		ans = min(ans , h1.qry(vec(H , L)) - nd[i + 1].x * H);
		if(p1 < p2) ans = min(ans , h2.qry(vec(H , L)) - nd[i + 1].x * H - dwn * L); else ans = min(ans , h2.qry(vec(H , L)) - nd[i + 1].x * H + up * L);
		if(max(p1 , p2) != N) ans = min(ans , (nd[max(p1 , p2) + 1].x - nd[i + 1].x) * H + (up - dwn) * L);
	}
}

signed main(){
	for(T = read() ; T ; --T){
		N = read(); ans = (N > 2) * 1e18; for(int i = 1 ; i <= N ; ++i){nd[i].x = read(); nd[i].y = read();}
		w1(); for(int i = 1 ; i <= N ; ++i){swap(nd[i].x , nd[i].y);} w1();
		w2(); for(int i = 1 ; i <= N ; ++i){nd[i].x = -nd[i].x;} w2(); w3(); printf("%lld\n" , ans);
	}
	return 0;
}