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
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	int lower_bound(V val) {
		V v0=0,v1=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) {
			if((ent+(1<<i)-1)*(v0+bit[0][ent+(1<<i)-1])+(v1+bit[1][ent+(1<<i)-1])<val) {
				v0+=bit[0][ent+(1<<i)-1];
				v1+=bit[1][ent+(1<<i)-1];
				ent+=(1<<i);
			}
		}
		return ent;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};
BIT_r<ll,20> bt;

int N,Q;
int A[202020];
int T,X,Y;
map<int,int> M,R;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[0]=M[0]=1<<30;
	R[-(1<<30)]=0;
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++) {
		scanf("%d",&A[i]);
		if(A[i-1]>A[i]) {
			M[i]=A[i];
			R[-A[i]]=i;
		}
		
		bt.add(i,i,A[i]);
	}
	bt.add(N+1,N+1,1LL<<32);
	M[N+1]=0;
	R[0]=N+1;
	while(Q--) {
		scanf("%d%d%d",&T,&X,&Y);
		if(T==1) {
			auto it=M.lower_bound(X+1);
			if(prev(it)->second>=Y) continue;
			y=1<<30;
			if(it->first!=X+1) {
				y=prev(it)->second;
				R[-y]=X+1;
				M[X+1]=y;
			}
			int px=X+1;
			while(1) {
				auto it=prev(M.lower_bound(X+1));
				if(it->second>Y) break;
				bt.add(it->first,px-1,Y-it->second);
				px=it->first;
				if(it->second!=y) R.erase(-it->second);
				M.erase(it);
			}
			M[px]=Y;
			R[-Y]=px;
		}
		else {
			int num=0;
			while(X<=N) {
				ll co=bt.total(X-1);
				auto p=bt.lower_bound(co+Y+1)-1;
				Y-=bt.total(p)-co;
				num+=p-(X-1);
				X=max(p+1,R.lower_bound(-Y)->second);
				//cout<<"!now" <<" "<<X<<" "<<Y<<" "<<num<<endl;
			}
			//FORR(r,M) cout<<r.first<<":"<<r.second<<" ";
			//cout<<endl;
			cout<<num<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}