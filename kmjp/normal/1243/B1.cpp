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

int Q,N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>S>>T;
		if(1) {
			map<int,int> M;
			FOR(i,N) if(S[i]!=T[i]) M[S[i]*256+T[i]]++;
			if(M.empty() || (M.size()==1 && M.begin()->second==2)) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			
			
		}
		else {
			vector<pair<int,int>> V;
			FOR(i,N) if(S[i]!=T[i]) {
				for(j=i+1;j<N;j++) {
					if(S[i]==S[j]) {
						V.push_back({j+1,i+1});
						swap(S[j],T[i]);
						break;
					}
					if(S[i]==T[j]) {
						V.push_back({j+1,j+1});
						swap(S[j],T[j]);
						V.push_back({j+1,i+1});
						swap(S[j],T[i]);
						break;
					}
				}
			}
			if(S==T) {
				cout<<"Yes"<<endl;
				cout<<V.size()<<endl;
				FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}