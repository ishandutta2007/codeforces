#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[101010];
int Q;
int L,R,X;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;
ll add=0;

void hoge() {
	ll cur=bt(1)+add;
	if(cur>=0) {
		cout<<(cur+1)/2<<endl;
	}
	else {
		cout<<cur/2<<endl;
	}
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int pre=0;
	FOR(i,N) {
		cin>>x;
		bt.add(i+1,x-pre);
		if(i&&x>pre) add+=x-pre;
		pre=x;
	}
	
	hoge();
	cin>>Q;
	FOR(i,Q) {
		cin>>L>>R>>X;
		ll a,b;
		if(L>1) {
			a=bt(L-1);
			b=bt(L);
			if(b>a) add-=b-a;
		}
		if(R+1<=N) {
			a=bt(R);
			b=bt(R+1);
			if(b>a) add-=b-a;
		}
		bt.add(L,X);
		bt.add(R+1,-X);
		if(L>1) {
			a=bt(L-1);
			b=bt(L);
			if(b>a) add+=b-a;
		}
		if(R+1<=N) {
			a=bt(R);
			b=bt(R+1);
			if(b>a) add+=b-a;
		}
		
		hoge();
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}