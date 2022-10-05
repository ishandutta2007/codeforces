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

int N,Q,A[101010];
int pre[101010];
int nex[101010];
int step[101010][20];
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	 static V const def=1LL<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<18> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pre);
	cin>>N>>Q;
	FOR(i,N) {
		nex[i]=N;
		cin>>A[i];
		for(j=2;j*j<=A[i];j++) if(A[i]%j==0) {
			if(pre[j]>=0) nex[pre[j]]=min(nex[pre[j]],i);
			pre[j]=i;
			while(A[i]%j==0) A[i]/=j;
		}
		if(A[i]>1) {
			j=A[i];
			if(pre[j]>=0) nex[pre[j]]=min(nex[pre[j]],i);
			pre[j]=i;
		}
	}
	for(i=N-1;i>=0;i--) {
		nex[i]=min(nex[i],st.getval(i+1,nex[i]));
		st.update(i,nex[i]);
		step[i][0]=nex[i]-1;
	}
	
	FOR(i,19) {
		FOR(j,N) {
			x=step[j][i];
			if(x>=N-1) step[j][i+1]=N;
			else step[j][i+1]=step[x+1][i];
		}
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		int ret=0;
		for(i=18;i>=0;i--) if(L<R&&step[L][i]<R) {
			ret+=1<<i;
			L=step[L][i]+1;
		}
		if(L<R) ret++;
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}