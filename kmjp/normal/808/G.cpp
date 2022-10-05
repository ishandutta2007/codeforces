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

string S,T;
int NS,NT;

int ma[101010][2];

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	NS=S.size();
	NT=T.size();
	
	vector<int> V=Zalgo(T);
	
	int ret=0;
	for(i=NS-NT;i>=0;i--) {
		ma[i][0]=max(ma[i+1][0],ma[i+1][1]);
		int hoge=max(ma[i+NT][0],ma[i+NT][1]);
		FOR(x,NT) {
			if(S[i+x]!='?' && S[i+x]!=T[x]) break;
			if(x && V[x]+x==NT) hoge=max(hoge,ma[i+x][1]);
		}
		if(x==NT) {
			ma[i][1]=1+hoge;
		}
		else {
			ma[i][1]=-1<<30;
		}
		ret=max({ret,ma[i][0],ma[i][1]});
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}