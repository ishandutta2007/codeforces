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

int N,Q;
int A[101010];
const ll mo=1000000007;
const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

template<class V,int NV> class SegTree_1 {
public:
	vector<vector<int>> val;
	
	SegTree_1(){val=vector<vector<int>>(NV*2);};
	vector<int> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {};
		if(x<=l && r<=y) return val[k];
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		if(a.empty()) return b;
		if(b.empty()) return a;
		int i;
		FOR(i,a.size()) a[i]=max(a[i],b[i]);
		return a;
	}
	void update(int entry, vector<int> v) {
		entry += NV;
		val[entry]=v;
	}
	void build() {
		for(int i=NV-1;i>=1;i--) {
			if(val[i*2].empty()) val[i]=val[i*2+1];
			else if(val[i*2+1].empty()) val[i]=val[i*2];
			else {
				val[i]=val[i*2];
				int j;
				FOR(j,val[i].size()) val[i][j]=max(val[i][j],val[i*2+1][j]);
			}
			
		}
	}
};
SegTree_1<int,1<<17> st;

template<int NV> class SegTree_2 {
public:
	vector<vector<int>> pres;
	vector<vector<int>> val;
	vector<vector<int>> mul;
	
	SegTree_2(){
		pres.resize(NV*2);
		val.resize(NV*2);
		mul.resize(NV*2);
	};
	ll getval(int x,int y,int v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 1;
		if(x<=l && r<=y) {
			int cur=lower_bound(ALL(pres[k]),v+1)-pres[k].begin();
			if(cur==0) return 1;
			return mul[k][cur-1];
		}
		return getval(x,y,v,l,(l+r)/2,k*2)*getval(x,y,v,(l+r)/2,r,k*2+1)%mo;
	}
	void set(int entry,int pre,ll v) {
		pres[entry+NV].push_back(pre);
		val[entry+NV].push_back(v);
		mul[entry+NV].push_back(v);
	}
	void build() {
		for(int i=NV-1;i>=1;i--) {
			int a=0,b=0;
			int x=i*2,y=i*2+1;
			ll cv=1;
			while(a<val[x].size() || b<val[y].size()) {
				if(a==val[x].size()) {
					takeb:
					pres[i].push_back(pres[y][b]);
					val[i].push_back(val[y][b]);
					(cv*=val[y][b])%=mo;
					mul[i].push_back(cv);
					b++;
				}
				else if(b==val[y].size()) {
					takea:
					pres[i].push_back(pres[x][a]);
					val[i].push_back(val[x][a]);
					(cv*=val[x][a])%=mo;
					mul[i].push_back(cv);
					a++;
				}
				else if(pres[x][a]<pres[y][b]) {
					goto takea;
				}
				else {
					goto takeb;
				}
			}
		}
	}
};
SegTree_2<1<<17> st2;

int pre[101010];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	map<int,int> M;
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		//A[i]=rand()%159999+1;
		vector<int> V;
		FOR(j,NP) {
			if(prime[j]>=448) break;
			x=1;
			while(A[i]%prime[j]==0) {
				x*=prime[j];
				A[i]/=prime[j];
			}
			V.push_back(x);
		}
		st.update(i,V);
		if(A[i]>1) {
			pre[i]=M[A[i]];
			M[A[i]]=i+1;
		}
		st2.set(i,pre[i],A[i]);
	}
	st.build();
	st2.build();
	cin>>Q;
	int last=0;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		//L=rand();
		//R=rand();
		
		L=(L+last)%N;
		R=(R+last)%N;
		if(L>R) swap(L,R);
		R++;
		ll ret=1;
		auto a=st.getval(L,R);
		FORR(v,a) ret=ret*v%mo;
		(ret*=st2.getval(L,R,L))%=mo;
		
		cout<<ret<<endl;
		last=ret;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}