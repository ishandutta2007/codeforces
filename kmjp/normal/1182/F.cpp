#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
ll A,B,P,Q;
ll D=33333;
ll C;
void check(ll b) { // b is better?
	ll x=2*P*C%(2*Q);
	ll y=2*P*b%(2*Q);
	if(abs(Q-y)<abs(Q-x)) C=b;
	if(abs(Q-y)==abs(Q-x)) C=min(C,b);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>P>>Q;
		ll g=__gcd(P,Q);
		P/=g;
		Q/=g;
		P%=Q;

		B++;
		C=A;
		while(A<B && (B-A)%D) {
			check(A);
			A++;
		}
		if(A<B) {
			vector<pair<ll,int>> V;
			unordered_set<ll> S;
			for(x=A;x<A+D;x++) {
				check(x);
				ll v=2*P*x%(2*Q);
				if(S.count(v)==0) {
					S.insert(v);
					V.push_back({v,x-A});
					V.push_back({v-2*Q,x-A});
					V.push_back({v+2*Q,x-A});
				}
			}
			sort(ALL(V));
			for(x=A;x<B;x+=D) {
				ll v=((Q-2*P*(x-A))%(2*Q)+2*Q)%(2*Q);;
				auto it=lower_bound(ALL(V),make_pair(v,0));
				check(x+it->second);
				it--;
				check(x+it->second);
			}
		}
		
		
		cout<<C<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}