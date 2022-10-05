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
string S;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
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
SegTree_1<int,1<<20> st;
int T[702020],P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	S+=S;
	FOR(i,2*N) {
		T[i+1]=T[i];
		if(S[i]=='(') T[i+1]++;
		else T[i+1]--;
		st.update(i+1,T[i+1]);
	}
	
	if(T[2*N]!=0) {
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		return;
	}
	
	int C[4]={};
	vector<int> neg,zero,pp;
	FOR(i,N) {
		x=st.getval(i,i+N);
		if(x==T[i]) {
			P[i]=1;
			zero.push_back(i);
			zero.push_back(i+N);
		}
		if(x==T[i]-1) {
			P[i]=2;
			neg.push_back(i);
			neg.push_back(i+N);
		}
		if(x==T[i]-2) {
			pp.push_back(i);
			pp.push_back(i+N);
		}
		C[P[i]]++;
	}
	sort(ALL(zero));
	sort(ALL(neg));
	sort(ALL(pp));
	int ma=C[1],L=0,R=0;
	FOR(i,zero.size()/2) {
		int lt=zero[i],rt=zero[i+zero.size()/2-1];
		int cnt=lower_bound(ALL(neg),rt)-lower_bound(ALL(neg),lt);
		
		//cout<<lt<<" "<<rt<<" "<<cnt<<" "<<C[1]+C[3]-cnt<<endl;
		if(C[2]-cnt>ma) {
			ma=C[2]-cnt;
			L=(lt+N-1)%N;
			R=(rt+1+N-1)%N;
		}
	}
	FORR(n,neg) zero.push_back(n);
	sort(ALL(zero));
	FOR(i,zero.size()-1) {
		int lt=zero[i],rt=zero[i+1];
		if(l>=N) break;
	
		int cnt=lower_bound(ALL(pp),zero[i+1])-lower_bound(ALL(pp),zero[i]);
		if(C[1]+cnt>ma) {
			ma=C[1]+cnt;
			L=(lt+N)%N;
			R=(rt+N-1)%N;
		}
		
	}
	
	cout<<ma<<endl;
	cout<<(L+1)<<" "<<(R+1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}