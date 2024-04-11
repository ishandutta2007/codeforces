#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,Q;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,20> bt;

int A[202020];
int L[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	
	FOR(i,N) {
		scanf("%d",&A[i]);
	}
	set<int> S;
	S.insert(N);
	S.insert(-1);
	FOR(i,N) {
		if(A[i]>A[i+1]) {
			S.insert(i);
			auto it=S.find(i);
			x=i-*prev(it);
			bt.add(i,1LL*x*(x+1)/2);
		}
	}
	FOR(i,Q) {

		/*
		FOR(j,N) cout<<A[j];
		cout<<" : ";
		FOR(j,N) cout<<bt(j)-bt(j-1);
		cout<<" : ";
		FORR(a,S) cout<<a;
		cout<<endl;
		*/
		scanf("%d%d%d",&j,&x,&y);
		
		
		if(j==1) {
			x--;
			
			if(x) bt.set(x-1,0),S.erase(x-1);
			bt.set(x,0),S.erase(x);
			A[x]=y;
			if(x&&A[x-1]>A[x]) {
				S.insert(x-1);
				auto it=S.find(x-1);
				k=x-1-*prev(it);
				bt.set(x-1,1LL*k*(k+1)/2);
			}
			if(A[x]>A[x+1]) {
				S.insert(x);
				auto it=S.find(x);
				k=x-*prev(it);
				bt.set(x,1LL*k*(k+1)/2);
			}

			auto it=S.lower_bound(x+1);
			if(*it!=N) {
				x=*it;
				y=x-*prev(it);
				bt.set(x,1LL*y*(y+1)/2);
			}

		}
		else {
			x--;
			auto it=S.lower_bound(x);
			ll pat=0;
			if(*it>=y) {
				y-=x;
				pat=1LL*y*(y+1)/2;
			}
			else {
				pat=bt(y-1)-bt(x-1);
				auto it=S.lower_bound(x);
				j=*it;
				pat-=bt(j)-bt(j-1);
				pat+=1LL*(j-x+1)*(j-x+2)/2;
				
				it=prev(S.lower_bound(y));
				y=y-*it-1;
				pat+=1LL*(y)*(y+1)/2;
			}
			cout<<pat<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}