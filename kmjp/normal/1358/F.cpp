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
vector<ll> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A.resize(N);
	B.resize(N);
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	if(A==B) {
		cout<<"SMALL"<<endl;
		cout<<"0"<<endl;
		cout<<endl;
		return;
	}
	
	if(N>=3) {
		string S;
		while(A!=B) {
			reverse(ALL(B));
			if(A==B) {
				S+="R";
				break;
			}
			reverse(ALL(B));
			FOR(i,N-1) if(B[i]>=B[i+1]) break;
			if(i<N-1) {
				reverse(ALL(B));
				S+="R";
			}
			FOR(i,N-1) if(B[i]>=B[i+1]) break;
			if(i<N-1) {
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
			S+="P";
			for(i=N-1;i>=1;i--) B[i]-=B[i-1];
		}
		reverse(ALL(S));
		int R=count(ALL(S),'P');
		if(R>200000) {
			cout<<"BIG"<<endl;
			cout<<R<<endl;
		}
		else {
			cout<<"SMALL"<<endl;
			cout<<S.size()<<endl;
			cout<<S<<endl;
		}
		return;
	}
	else if(N==2) {
		ll np=0;
		vector<pair<char,ll>> S;
		while(A!=B) {
			reverse(ALL(B));
			if(A==B) {
				S.push_back({'R',1});
				break;
			}
			reverse(ALL(B));
			if(B[0]>B[1]) {
				reverse(ALL(B));
				S.push_back({'R',1});
			}
			if(B[0]==B[1] || B[0]<min(A[0],A[1]) || B[1]<max(A[0],A[1])) {
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
			
			if(B[0]==min(A[0],A[1])) {
				if((B[1]-max(A[0],A[1]))%B[0]==0) {
					np+=(B[1]-max(A[0],A[1]))/B[0];
					S.push_back({'P',(B[1]-max(A[0],A[1]))/B[0]});
					B[1]=max(A[0],A[1]);
				}
				else {
					cout<<"IMPOSSIBLE"<<endl;
					return;
				}
			}
			else {
				np+=B[1]/B[0];
				S.push_back({'P',B[1]/B[0]});
				B[1]%=B[0];
			}
		}
		if(np>200000) {
			cout<<"BIG"<<endl;
			cout<<np<<endl;
		}
		else {
			string T;
			FORR(c,S) {
				FOR(x,c.second) T+=c.first;
			}
			reverse(ALL(T));
			cout<<"SMALL"<<endl;
			cout<<T.size()<<endl;
			cout<<T<<endl;
		}
		return;
	}
	cout<<"IMPOSSIBLE"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}