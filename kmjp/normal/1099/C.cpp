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

string S;
int K;
int A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	FORR(c,S) {
		if(c=='?') B++;
		else if(c=='*') C++;
		else A++;
	}
	
	if(A<K) {
		if(C) {
			C=K-A;
			char p;
			FORR(c,S) {
				if(c=='*' && C) {
					while(C>0) {
						cout<<p;
						C--;
					}
				}
				else if(c>='a' && c<='z') {
					cout<<c;
					p=c;
				}
			}
			cout<<endl;
		}
		else {
			cout<<"Impossible"<<endl;
		}
	}
	else if(A-B-C<=K) {
		if(A-B<=K) B=A-K;
		if((A-B)-C<=K) C=(A-B)-K;
		string R;
		FORR(c,S) {
			if(c=='?') {
				if(B>0) {
					R.pop_back();
					B--;
				}
			}
			else if(c=='*') {
				if(C>0) {
					R.pop_back();
					C--;
				}
			}
			else {
				R.push_back(c);
			}
		}
		cout<<R<<endl;
		
	}
	else {
		cout<<"Impossible"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}