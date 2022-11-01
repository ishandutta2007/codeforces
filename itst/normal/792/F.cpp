#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e6;
#define PII pair < int , int >
#define st first
#define nd second
set < PII > node; int N , M , O , lst;

PII operator -(PII A , PII B){return PII(A.st - B.st , A.nd - B.nd);}
long long operator %(PII A , PII B){return A.st * B.nd - A.nd * B.st;}

void insert(PII now){
	auto p = node.lower_bound(now);
	if(p != node.end() && p->st == now.st) return;
	if(p != node.begin()) (--p)->st == now.st ? node.erase(p++) : ++p;
	if(p != node.begin() && p != node.end()){
		auto p1 = p; --p1;
		if((now - *p1) % (*p - *p1) >= 0) return;
	}
	auto p1 = p;
	if(p != node.begin()){
		if(--p1 != node.begin()){
			auto p2 = p1; --p2;
			while((*p1 - *p2) % (now - *p2) >= 0){node.erase(p1); if(p2 != node.begin()) p1 = p2--; else{p1 = p2; break;}}
		}
		++p1;
	}
	if(p != node.end()) while(++p != node.end() && (*p1 - now) % (*p - now) >= 0){node.erase(p1); p1 = p;}
	node.insert(now);
	if(node.size() >= 2 && (--node.end())->nd < (----node.end())->nd) node.erase(--node.end());
}

bool check(int A , int B){return 2e18 / B <= A;}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> M; node.insert(PII(0 , 0));
	for(int i = 1 ; i <= N ; ++i){
		int X , A , B; cin >> X >> A >> B;
		A = (A + lst) % MOD + 1; B = (B + lst) % MOD + 1;
		if(X == 1) insert(PII(B , A));
		else{
			auto t = node.lower_bound(PII(M / A - (M % A ? 0 : 1) , 1e18));
			if(t == node.end()) lst = (--t)->nd * A >= B ? i : lst;
			else{
				auto q = t--;
				/*long double atk = (long double)(q->nd - t->nd) / (q->st - t->st) * ((long double)M / A - t->st) + t->nd;
				  lst = atk * A >= B ? i : lst;*/
				lst = check(q->nd - t->nd , M - A * t->st) || check(A * t->nd , q->st - t->st) ||
				  B * (q->st - t->st) <= (q->nd - t->nd) * (M - A * t->st) + A * t->nd * (q->st - t->st) ? i : lst;
			}
			puts(i == lst ? "YES" : "NO");
		}
	}
	return 0;
}