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
string F[101010];
int T[101010];
int E;

set<string> A,B;
set<string> AB,BA,FA,FB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>F[i]>>T[i];
		if(T[i]==1) E++;
	}
	
	for(i=1;i<=N;i++) {
		string s=to_string(i);
		if(i<=E) A.insert(s);
		else B.insert(s);
	}
	
	FOR(i,N) {
		if(A.count(F[i])) {
			A.erase(F[i]);
			if(T[i]==0) AB.insert(F[i]);
		}
		else if(B.count(F[i])) {
			B.erase(F[i]);
			if(T[i]==1) BA.insert(F[i]);
		}
		else {
			if(T[i]==0) FB.insert(F[i]);
			else FA.insert(F[i]);
		}
	}
	
	vector<pair<string,string>> R;
	while(A.size() || B.size() || AB.size() || BA.size()) {
		if(A.size() && BA.size()) {
			R.push_back({*BA.begin(),*A.begin()});
			A.erase(A.begin());
			B.insert(*BA.begin());
			BA.erase(BA.begin());
			continue;
		}
		if(B.size() && AB.size()) {
			R.push_back({*AB.begin(),*B.begin()});
			B.erase(B.begin());
			A.insert(*AB.begin());
			AB.erase(AB.begin());
			continue;
		}
		if(A.size() && FA.size()) {
			R.push_back({*FA.begin(),*A.begin()});
			A.erase(A.begin());
			FA.erase(FA.begin());
			continue;
		}
		if(B.size() && FB.size()) {
			R.push_back({*FB.begin(),*B.begin()});
			B.erase(B.begin());
			FB.erase(FB.begin());
			continue;
		}
		assert(AB.size()==BA.size() && AB.size());
		A.insert(*AB.begin());
		R.push_back({*AB.begin(),"zzzzz"});
		AB.erase(AB.begin());
		FB.insert("zzzzz");
	}
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<"move "<<r.first<<" "<<r.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}