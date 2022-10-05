#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

string S;
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

int N;
map<string,int> R;
int Q;
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	vector<int> V=Zalgo(S);
	
	for(i=1;i<N;i++) if(i+V[i]==N) {
		string C;
		for(j=1;j<=10;j++) {
			C+=S[(N-i)+(j-1)%i];
			R[C]=max(R[C],(N-i)+j);
		}
	}
	cin>>Q;
	while(Q--) {
		cin>>T;
		S+=T;
		for(i=1;i<=T.size();i++) {
			int ma=R[T.substr(0,i)];
			for(j=1;j<=i;j++) if(S.substr(0,j)==T.substr(i-j,j)) ma=max(ma,j);
			cout<<ma<<" ";
		}
		cout<<endl;
		FOR(i,T.size()) S.pop_back();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}