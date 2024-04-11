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
ll A[302020],B[302020],SB[202020];
ll ret[303030];

ll mo=1000000007;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> sum,mul;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(r,2) {
		ZERO(sum.bit);
		ZERO(mul.bit);
		vector<ll> Bs;
		Bs.push_back(0);
		FOR(i,N) {
			SB[i+1]=SB[i]+B[i];
			Bs.push_back(SB[i+1]);
			Bs.push_back(SB[i+1]-B[i]);
		}
		sort(ALL(Bs));
		Bs.erase(unique(ALL(Bs)),Bs.end());
		FOR(i,N) if(B[i]>0) {
			x=lower_bound(ALL(Bs),SB[i+1]-B[i])-Bs.begin();
			y=lower_bound(ALL(Bs),SB[i+1])-Bs.begin();
			sum.add(0,A[i]*B[i]%mo);
			sum.add(x,mo-A[i]*B[i]%mo);
			sum.add(y,mo-A[i]*B[i]%mo);
			
			mul.add(x,mo-2*A[i]%mo);
			mul.add(y,2*A[i]%mo);
			sum.add(x,A[i]*(2*SB[i+1]%mo-B[i])%mo);
			sum.add(y,mo-A[i]*(2*SB[i+1]%mo-B[i])%mo);
		}
		FOR(i,N) {
			x=lower_bound(ALL(Bs),SB[i+1]-B[i])-Bs.begin();
			y=lower_bound(ALL(Bs),SB[i+1])-Bs.begin();
			ret[i]+=sum(x)+SB[i]%mo*mul(x)%mo;
			if(B[i]>0) {
				/*
				cout<<i<<" "<<B[i]<<" "<<SB[i]<<" "<<A[i]<<endl;
				FOR(j,Bs.size()) cout<<" "<<j<<" "<<Bs[j]<<" "<<sum(j)<<" + "<<Bs[j]<<"*"<<mul(j)<<" = "<<(sum(j)+Bs[j]*mul(j))<<endl;
				*/
				
				sum.add(0,mo-A[i]*B[i]%mo);
				sum.add(x,A[i]*B[i]%mo);
				sum.add(y,A[i]*B[i]%mo);

				mul.add(x,2*A[i]%mo);
				mul.add(y,mo-2*A[i]%mo);
				sum.add(x,mo-A[i]*(2*SB[i+1]%mo-B[i])%mo);
				sum.add(y,A[i]*(2*SB[i+1]%mo-B[i])%mo);
			}
		}
		
		FOR(i,N) B[i]=-B[i];
		//FOR(i,N+1) cout<<"!"<<i<<" "<<(ret[i]+mo)%mo<<endl;
		
	}
	
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		cout<<((ret[R]-ret[L-1])%mo+mo)%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}