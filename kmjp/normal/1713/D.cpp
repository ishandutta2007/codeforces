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


int T,N;

int ask(int x,int y) {
	cout<<"? "<<(x+1)<<" "<<(y+1)<<endl;
	cin>>x;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V;
		FOR(i,1<<N) V.push_back(i);
		while(V.size()>2) {
			vector<int> W;
			for(i=0;i<V.size();i+=4) {
				int a=V[i];
				int b=V[i+1];
				int c=V[i+2];
				int d=V[i+3];
				
				x=ask(a,c);
				if(x==0) {
					x=ask(b,d);
					if(x==1) W.push_back(b);
					else W.push_back(d);
				}
				else if(x==1) {
					x=ask(a,d);
					if(x==1) W.push_back(a);
					else W.push_back(d);
				}
				else {
					x=ask(b,c);
					if(x==1) W.push_back(b);
					else W.push_back(c);
				}
			}
			V=W;
		}
		if(V.size()==2) {
			x=ask(V[0],V[1]);
			if(x==1) {
				V={V[0]};
			}
			else {
				V={V[1]};
			}
		}
		cout<<"! "<<V[0]+1<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}