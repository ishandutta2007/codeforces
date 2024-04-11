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
vector<vector<int>> E;

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	x = v1.second;
	y = v2.second;
	int d=D[0][y];
	vector<int> dia(d+1);
	ll ret=1LL*d*(d+1)/2;
	
	vector<vector<int>> V;
	FOR(i,N) {
		if(D[0][i]+D[1][i]==d) {
			dia[D[0][i]]=i+1;
		}
		else if(D[0][i]>D[1][i]) {
			ret+=D[0][i];
			V.push_back({D[0][i],x+1,i+1});
		}
		else {
			ret+=D[1][i];
			V.push_back({D[1][i],y+1,i+1});
		}
	}
	cout<<ret<<endl;
	sort(ALL(V));
	reverse(ALL(V));
	FORR(v,V) {
		cout<<v[1]<<" "<<v[2]<<" "<<v[2]<<endl;
	}
	
	while(dia.size()>1) {
		cout<<dia[0]<<" "<<dia.back()<<" "<<dia.back()<<endl;
		dia.pop_back();
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}