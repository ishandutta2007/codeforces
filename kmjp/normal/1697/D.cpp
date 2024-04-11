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

int N;
string S;
int pre[26];

int ask(int L,int R) {
	int num;
	cout<<"? 2 "<<L+1<<" "<<R+1<<endl;
	cin>>num;
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	S.resize(N);
	MINUS(pre);
	FOR(i,N) {
		vector<pair<int,char>> V;
		FOR(j,26) if(pre[j]>=0) V.push_back({pre[j],'a'+j});
		sort(ALL(V));
		reverse(ALL(V));
		x=ask(0,i);
		if(x==V.size()+1) {
			cout<<"? 1 "<<(i+1)<<endl;
			cin>>S[i];
		}
		else {
			x=V.size()-1;
			for(j=10;j>=0;j--) if(x-(1<<j)>=0) {
				y=ask(V[x-(1<<j)].first,i);
				if(y==x-(1<<j)+1) x-=1<<j;
			}
			S[i]=V[x].second;
		}
		pre[S[i]-'a']=i;
	}
	cout<<"! "<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}