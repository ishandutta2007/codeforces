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

int Q,D,A[202020];
int is[202020];

template<class V,int NV> class SegTree_sum {
public:
	vector<V> avail,op,ssum,ssq;
	
	SegTree_sum(){
		avail.resize(NV*2);
		op.resize(NV*2);
		ssum.resize(NV*2);
		ssq.resize(NV*2);
	};
	
	
	void prop(int k,int v) {
		if(v>0) {
			ssq[k]+=v*ssum[k]+avail[k]*v*(v-1)/2;
			ssum[k]+=v*avail[k];
			op[k]+=v;
		}
		if(v<0) {
			v=-v;
			ssum[k]-=v*avail[k];
			ssq[k]-=v*ssum[k]+avail[k]*v*(v-1)/2;
			op[k]-=v;
		}
		
	}
	void update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return;
		if(x<=l&&r<=y) {
			if(v==1) {
				ssq[k]+=ssum[k];
				ssum[k]+=avail[k];
				op[k]++;
			}
			else {
				ssum[k]-=avail[k];
				ssq[k]-=ssum[k];
				op[k]--;
			}
		}
		else {
			prop(2*k,op[k]);
			prop(2*k+1,op[k]);
			op[k]=0;
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			avail[k]=avail[2*k]+avail[2*k+1];
			ssum[k]=ssum[2*k]+ssum[2*k+1];
			ssq[k]=ssq[2*k]+ssq[2*k+1];
		}
	}
	void update2(int x,int y,int av,int nv,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return;
		if(x<=l&&r<=y) {
			op[k]=0;
			if(av==1) {
				avail[k]=1;
				ssum[k]=nv;
				ssq[k]=1LL*nv*(nv-1)/2;
			}
			else {
				avail[k]=0;
				ssum[k]=0;
				ssq[k]=0;
			}
		}
		else {
			prop(2*k,op[k]);
			prop(2*k+1,op[k]);
			op[k]=0;
			update2(x,y,av,nv,l,(l+r)/2,k*2);
			update2(x,y,av,nv,(l+r)/2,r,k*2+1);
			avail[k]=avail[2*k]+avail[2*k+1];
			ssum[k]=ssum[2*k]+ssum[2*k+1];
			ssq[k]=ssq[2*k]+ssq[2*k+1];
		}
	}
};
SegTree_sum<ll,1<<18> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>D;
	ll sum=0;
	FOR(i,Q) {
		int R;
		cin>>R;
		R--;
		int L=max(0,R-D);
		
		if(is[R]==0) {
			st.update(L,R,1);
			x=bt(R+D)-bt(R);
			st.update2(R,R+1,1,x);
			bt.add(R,1);
		}
		else {
			st.update(L,R,0);
			st.update2(R,R+1,0,0);
			bt.add(R,-1);
		}
		is[R]^=1;
		cout<<st.ssq[1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}