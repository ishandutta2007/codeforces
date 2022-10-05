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

int mo=(441LL<<21)+1;

inline int mulmod(int a,int b) {
	int d,r;
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

int modpow(int a, int n = mo-2) {
	int r=1;
	while(n) r=mulmod(r,((n%2)?a:1)),a=mulmod(a,a),n>>=1;
	return r;
}
vector<int> fft(vector<int> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		ll wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			ll w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=mulmod(w,v[j2]);
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				//w=w*wn%mo;
				w=mulmod(w,wn);
			}
		}
	}
	if(rev) {
		int rv = modpow(n);
		FOR(i,n) v[i]=mulmod(v[i],rv);
	}
	return v;
}

vector<int> MultPoly(vector<int> P,vector<int> Q,bool resize=true) {
	int ps=P.size();
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(P[i]) pi=i;
		FOR(i,Q.size()) if(Q[i]) qi=i;
		maxind=pi+qi+2;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	if(P==Q) {
		P=Q=fft(P);
	}
	else {
		P=fft(P), Q=fft(Q);
	}
	for(int i=0;i<P.size();i++) P[i]=mulmod(P[i],Q[i]);
	auto PQ=fft(P,true);
	PQ.push_back(0);
	for(int i=0;i<PQ.size()-1;i++) {
		PQ[i+1]+=PQ[i]/100;
		PQ[i]%=100;
	}
	while(PQ.back()==0) PQ.pop_back();
	PQ.push_back(0);
	return PQ;
}

int lessless(vector<int> X,vector<int> Y) {
	for(int i=max(X.size(),Y.size())-1;i>=0;i--) {
		if(i>=X.size()) {
			if(Y[i]) return 1;
		}
		else if(i>=Y.size()) {
			if(X[i]) return 0;
		}
		else {
			if(X[i]<Y[i]) return 1;
			if(X[i]>Y[i]) return 0;
		}
	}
	return 0;
}

string S;
int mi=1<<30;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	if(S.size()==1 && S<="5") {
		cout<<S<<endl;
		return;
	}
	vector<int> P(S.size()/2+2);
	FOR(i,S.size()) {
		x=(S.size()-1-i)/2;
		P[x]=P[x]*10+S[i]-'0';
	}
	
	vector<int> R(1,4);
	int target=max(0.0,(S.size()-1)*log(10)/log(3)-2);
	int num=3;
	vector<int> Q(1,3);
	FOR(x,22) {
		if(target&(1<<x)) {
			target^=(1<<x);
			R=MultPoly(Q,R);
			num+=(3<<x);
		}
		if(target==0) break;
		
		Q=MultPoly(Q,Q);
	}
	R.push_back(0);
	while(lessless(R,P)) {
		auto QR=R;
		if(QR.back()==0) QR.push_back(0);
		FOR(i,QR.size()) QR[i]*=3;
		FOR(i,QR.size()) if(QR[i]>=100) QR[i+1] += QR[i]/100, QR[i] %= 100;
		if(lessless(QR,P)) R=QR, num+=3;
		else break;
	}
	
	mi=4+num;
	for(i=R.size()-1;i>=0;i--) {
		if(R[i]%2) R[i-1]+=100;
		R[i]/=2;
	}
	
	auto QR=R;
	FOR(i,QR.size()) QR[i]*=3;
	FOR(i,QR.size()) if(QR[i]>=100) QR[i+1] += QR[i]/100, QR[i] %= 100;
	if(lessless(QR,P)) R=QR, num+=3;
	mi=min(mi,2+num);
	for(i=R.size()-1;i>=0;i--) {
		if(R[i]%2) R[i-1]+=100;
		R[i]/=2;
	}
	
	QR=R;
	FOR(i,QR.size()) QR[i]*=3;
	FOR(i,QR.size()) if(QR[i]>=100) QR[i+1] += QR[i]/100, QR[i] %= 100;
	if(lessless(QR,P)) R=QR, num+=3;
	mi=min(mi,num);
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}