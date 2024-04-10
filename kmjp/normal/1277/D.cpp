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
string S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> C[2][2];
		set<string> SS;
		FOR(i,N){
			cin>>S[i];
			C[S[i][0]-'0'][S[i].back()-'0'].push_back(i+1);
			SS.insert(S[i]);
		}
		if(C[0][0].size() && C[1][1].size() && C[0][1].size()+C[1][0].size()==0) {
			cout<<-1<<endl;
			continue;
		}
		x=C[0][1].size();
		y=C[1][0].size();
		vector<int> R;
		int num=abs(x-y)/2;
		if(x>y) {
			FORR(r,C[0][1]) if(num) {
				s=S[r-1];
				reverse(ALL(s));
				if(SS.count(s)==0) {
					R.push_back(r);
					num--;
				}
			}
		}
		else {
			FORR(r,C[1][0]) if(num) {
				s=S[r-1];
				reverse(ALL(s));
				if(SS.count(s)==0) {
					R.push_back(r);
					num--;
				}
			}
		}
		if(num) {
			cout<<-1<<endl;
		}
		else {
			cout<<R.size()<<endl;
			FORR(r,R) cout<<r<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}