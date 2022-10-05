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
int num=0;
vector<int> ID[3];

string hoge(string S,int a,int b=-1) {
	if(b>=0) S.erase(S.begin()+b);
	S.erase(S.begin()+a);
	reverse(ALL(S));
	while(S.size()>1 && S.back()=='0') S.pop_back();
	reverse(ALL(S));
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) {
		num += S[i]-'0';
		num %= 3;
		ID[(S[i]-'0')%3].push_back(i);
	}
	FOR(i,3) reverse(ALL(ID[i]));
	
	
	vector<string> C;
	if(num==0) {
		C.push_back(S);
	}
	else if(num==1) {
		if(ID[1].size()>=1) C.push_back(hoge(S,ID[1][0]));
		if(ID[2].size()>=2) C.push_back(hoge(S,ID[2][1],ID[2][0]));
	}
	else {
		if(ID[2].size()>=1) C.push_back(hoge(S,ID[2][0]));
		if(ID[1].size()>=2) C.push_back(hoge(S,ID[1][1],ID[1][0]));
	}
	
	string R;
	FORR(r,C) if(R.size()<r.size()) R=r;
	
	if(R=="") cout<<-1<<endl;
	else cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}