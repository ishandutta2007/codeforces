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
vector<pair<char,int>> V;
int ma;

int from[26];
int to[26];

vector<pair<char,int> > RLE(string S) {
	vector<pair<char,int> > V;
	FORR(r,S) {
		r-='a';
		if(V.size() && V.back().first==r) V.back().second++;
		else V.push_back({r,1});
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S;
		auto A=RLE(S);
		
		FOR(j,26) to[j]=(from[j]>0?1:0);
		FORR(a,A) to[a.first]=max(to[a.first],a.second);
		if(A.size()==1) {
			to[A[0].first]=max(to[A[0].first],(from[A[0].first]+1)*A[0].second+from[A[0].first]);
		}
		else {
			if(A[0].first==A.back().first && from[A[0].first]) {
				to[A[0].first]=max(to[A[0].first],1+A[0].second+A.back().second);
			}
			if(from[A[0].first]) {
				to[A[0].first]=max(to[A[0].first],1+A[0].second);
			}
			if(from[A.back().first]) {
				to[A[0].first]=max(to[A[0].first],1+A.back().second);
			}
		}
		memmove(from,to,sizeof(from));
	}
	FOR(j,26) ma=max(ma,from[j]);
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}