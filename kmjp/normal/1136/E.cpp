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

int N;
ll A[101010],K[101010];
int Q;

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	V get(int entry) {
		return total(entry)-total(entry-1);
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};
BIT_r<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i+1];
		bt.add(i+1,i+1,A[i+1]);
	}
	set<int> B;
	for(i=1;i<=N-1;i++) {
		cin>>K[i];
		if(bt.get(i+1)-bt.get(i)!=K[i]) B.insert(i+1);
	}
	A[N+1]=1LL<<60;
	B.insert(N+1);
	cin>>Q;
	FOR(i,Q) {
		cin>>s>>x>>y;
		if(s=="+") {
			while(y) {
				int nex=*B.lower_bound(x+1);
				bt.add(x,nex-1,y);
				if(x>1) {
					if(bt.get(x)-bt.get(x-1)!=K[x-1]) {
						B.insert(x);
					}
					else {
						B.erase(x);
					}
				}
				if(nex>N) break;
				if(bt.get(nex)-bt.get(nex-1)>=K[nex-1]) {
					B.insert(nex);
					break;
				}
				y=K[nex-1]-(bt.get(nex)-bt.get(nex-1));
				x=nex;
			}
		}
		else {
			cout<<bt.total(y)-bt.total(x-1)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}