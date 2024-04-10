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
int D[101010];
pair<int,int> P[101010];
int num[202020];
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>D[i];
		P[i]={D[i],i};
	}
	sort(P,P+N);
	reverse(P,P+N);
	
	FOR(i,N) {
		num[i]=P[i].second*2+1;
		if(i) V.push_back({num[i],num[i-1]});
	}
	FOR(i,N) {
		if(num[i+P[i].first]==0) num[i+P[i].first]=P[i].second*2+2;
		V.push_back({P[i].second*2+2,num[i+P[i].first-1]});
	}
	
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}