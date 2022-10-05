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
vector<pair<int,int>> V;

set<pair<int,int>> seg;
map<int,int> M;
int bn=0,bk=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		V.push_back({x,i+1});
	}
	
	seg.insert({-1,1});
	seg.insert({N+2,1});
	sort(ALL(V));
	FORR(v,V) {
		x=v.second;
		y=1;
		auto it=seg.lower_bound({x,0});
		if(it->first==x+1) {
			i=it->second;
			if(--M[i]==0) M.erase(i);
			y+=it->second;
			seg.erase(it);
		}
		it=seg.lower_bound({x,0});
		it--;
		if(it->first+it->second==x) {
			i=it->second;
			if(--M[i]==0) M.erase(i);
			x=it->first;
			y+=it->second;
			seg.erase(it);
		}
		seg.insert({x,y});
		M[y]++;
		
		if(M.size()==1 && M.begin()->second>bn) {
			bn=M.begin()->second;
			bk=v.first+1;
		}
		
		
	}
	cout<<bk<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}