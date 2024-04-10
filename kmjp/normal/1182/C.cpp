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
vector<int> V[1010101][5];
string S[101010];

pair<int,char> count(string S) {
	char ch='0';
	int num=0;
	FORR(c,S) {
		if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') {
			num++;
			ch=c;
		}
	}
	if(ch=='a') ch=0;
	if(ch=='i') ch=1;
	if(ch=='u') ch=2;
	if(ch=='e') ch=3;
	if(ch=='o') ch=4;
	
	return {num,ch};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		auto p=count(S[i]);
		
		if(p.first) V[p.first][p.second].push_back(i);
	}
	
	vector<pair<int,int>> R;
	for(i=1;i<=1000000;i++) {
		FOR(x,5) {
			while(V[i][x].size()>=2) {
				j=V[i][x].back();
				V[i][x].pop_back();
				y=V[i][x].back();
				V[i][x].pop_back();
				R.push_back({j,y});
			}
		}
	}
	int C=R.size();
	for(i=1;i<=1000000;i++) {
		for(x=1;x<5;x++) if(V[i][x].size()) V[i][0].push_back(V[i][x][0]);
		x=0;
		while(V[i][x].size()>=2) {
			j=V[i][x].back();
			V[i][x].pop_back();
			y=V[i][x].back();
			V[i][x].pop_back();
			R.push_back({j,y});
		}
	}
	C=min(C,(int)R.size()/2);
	cout<<C<<endl;
	FOR(i,C) {
		cout<<S[R[C+i].first]<<" "<<S[R[i].first]<<endl;
		cout<<S[R[C+i].second]<<" "<<S[R[i].second]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}