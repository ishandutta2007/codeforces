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

int T;
int N;
int P[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V,S;
		V.push_back(0);
		FOR(i,N) {
			cin>>P[i];
			if(i) if(P[i]!=P[i-1]) V.push_back(0);
			V.back()++;
		}
		S.push_back(0);
		FORR(v,V) S.push_back(S.back()+v);
		int R[3]={};
		int A,B,C;
		for(A=B=C=1;A<=V.size();A++) {
			B=max(A,B);
			while(B+1<=V.size() && S[B]-S[A]<=S[A]) B++;
			C=max(B,C);
			while(C+1<=V.size() && S[C]-S[B]<=S[A]) C++;
			while(C+1<=V.size() && S[C+1]*2<=N) C++;
			
			//cout<<A<<B<<C<<" "<<S[A]<<" "<<S[B]-S[A]<<" "<<S[C]-S[B]<<endl;
			if(S[A]<S[B]-S[A] && S[C]-S[B]>S[A] && S[C]*2<=N) {
				//cout<<"!"<<endl;
				if(R[0]+R[1]+R[2]<S[C]) {
					R[0]=S[A];
					R[1]=S[B]-S[A];
					R[2]=S[C]-S[B];
				}
			}
			
		}
		cout<<R[0]<<" "<<R[1]<<" "<<R[2]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}