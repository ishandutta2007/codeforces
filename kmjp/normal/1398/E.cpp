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

BIT<ll,20> num,sum;

int N;
int T[202020],D[202020];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V.push_back(0);
	FOR(i,N) {
		cin>>T[i]>>D[i];
		if(D[i]>0) V.push_back(D[i]);
	}
	sort(ALL(V));
	set<int> S;
	FOR(i,N) {
		x=lower_bound(ALL(V),abs(D[i]))-V.begin();
		if(D[i]>0) {
			num.add(x,1);
			sum.add(x,D[i]);
			if(T[i]) S.insert(x);
		}
		else {
			num.add(x,-1);
			sum.add(x,D[i]);
			if(T[i]) S.erase(x);
		}
		
		if(S.empty()) {
			cout<<sum(N+1)<<endl;
		}
		else {
			x=*S.begin();
			ll ret=sum(N+1);
			num.add(x,-1);
			sum.add(x,-V[x]);
			
			y=num.lower_bound(num(N+1)-S.size());
			ret+=sum(N+1)-sum(y);
			
			num.add(x,1);
			sum.add(x,V[x]);
			cout<<ret<<endl;
			
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}