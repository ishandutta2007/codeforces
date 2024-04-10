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

int N,Q,last;
int T[202020],X[202020],Y[202020];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};

const int DI=1200;
UF_pop<200020> uf;
pair<int,int> p(int a,int b) { return {min(a,b),max(a,b)};};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>T[i]>>X[i]>>Y[i];
		X[i]--,Y[i]--;
	}
	
	set<pair<int,int>> S;
	string R;
	
	for(int start=0;start<Q;start+=DI) {
		set<pair<int,int>> A=S,B;
		vector<pair<int,int>> V;
		uf.reinit();
		for(i=start;i<min(start+DI,Q);i++) {
			if(T[i]==1) {
				if(A.count(p(X[i],Y[i]))) {
					A.erase(p(X[i],Y[i]));
					B.insert(p(X[i],Y[i]));
				}
				if(A.count(p((X[i]+1)%N,(Y[i]+1)%N))) {
					A.erase(p((X[i]+1)%N,(Y[i]+1)%N));
					B.insert(p((X[i]+1)%N,(Y[i]+1)%N));
				}
				
			}
		}
		FORR(a,A) uf(a.first,a.second);
		FORR(b,B) {
			V.push_back(b);
			uf(b.first,b.second);
			
		}
		for(i=start;i<min(start+DI,Q);i++) {
			X[i]+=last;
			X[i]%=N;
			Y[i]+=last;
			Y[i]%=N;
			if(T[i]==1) {
				
				if(B.count(p(X[i],Y[i]))) {
					B.erase(p(X[i],Y[i]));
					S.erase(p(X[i],Y[i]));
					vector<pair<int,int>> T;
					while(1) {
						uf.pop();
						if(V.back()==p(X[i],Y[i])) {
							V.pop_back();
							break;
						}
						else {
							T.push_back(V.back());
							V.pop_back();
						}
					}
					FORR(t,T) {
						V.push_back(t);
						uf(t.first,t.second);
					}
				}
				else {
					B.insert(p(X[i],Y[i]));
					S.insert(p(X[i],Y[i]));
					V.push_back(p(X[i],Y[i]));
					uf(X[i],Y[i]);
				}
				
			}
			else {
				last=uf[X[i]]==uf[Y[i]];
				R+='0'+last;
			}
			
		}
	}
	cout<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}