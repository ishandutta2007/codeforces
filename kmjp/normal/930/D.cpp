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
int U[2][205020];
int D[2][205020];
int L[2][205020];
int R[2][205020];
int X[101010],Y[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt[2][2];

vector<int> add[202020];
vector<int> del[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,202200) {
		D[0][i]=D[1][i]=20202000;
		U[0][i]=U[1][i]=-20202000;
		R[0][i]=R[1][i]=20202000;
		L[0][i]=L[1][i]=-20202000;
	}
		
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]+=101000;
		Y[i]+=101000;
		j=(X[i]+Y[i])%2;
		D[j][X[i]]=min(D[j][X[i]],Y[i]+1);
		U[j][X[i]]=max(U[j][X[i]],Y[i]-1);
		R[j][Y[i]]=min(R[j][Y[i]],X[i]+1);
		L[j][Y[i]]=max(L[j][Y[i]],X[i]-1);
	}
	FOR(j,2) {
		FOR(i,202000) {
			U[j][i+1]=max(U[j][i+1],U[j][i]-1);
			D[j][i+1]=min(D[j][i+1],D[j][i]+1);
			L[j][i+1]=max(L[j][i+1],L[j][i]-1);
			R[j][i+1]=min(R[j][i+1],R[j][i]+1);
		}
		for(i=202000;i>=0;i--) {
			U[j][i]=max(U[j][i],U[j][i+1]-1);
			D[j][i]=min(D[j][i],D[j][i+1]+1);
			L[j][i]=max(L[j][i],L[j][i+1]-1);
			R[j][i]=min(R[j][i],R[j][i+1]+1);
			if(D[j][i]<=U[j][i]) {
				add[D[j][i]].push_back(i);
				del[U[j][i]].push_back(i);
			}
		}
	}
	ll ret=0;
	FOR(i,202000) {
		FORR(a,add[i]) {
			bt[i%2][a%2].add(a,1);
		}
		FOR(j,2) {
			if(R[j][i]<=L[j][i]) {
				ret+=bt[i%2][R[j][i]%2](L[j][i])-bt[i%2][R[j][i]%2](R[j][i]-1);
			}
		}
		FORR(a,del[i]) {
			bt[i%2][a%2].add(a,-1);
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}