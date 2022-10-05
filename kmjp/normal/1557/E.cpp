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

int T;

string go(int y,int x) {
	cout<<(y+1)<<" "<<(x+1)<<endl;
	string s;
	cin>>s;
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		x=y=0;
		s=go(y,x);
		if(s=="Done") continue;
		
		int turn=0;
		while(1) {
			int up=0;
			
			FOR(i,7) {
				if(turn==0) x++;
				else x--;
				s=go(y,x);
				if(s=="Done") break;
				if(s.substr(0,2)=="Up") up++;
				if(s.substr(0,2)=="Do") {
					y++;
					s=go(y,x);
					if(s=="Done") break;
					up=-1;
					break;
				}
			}
			
			if(up==-1) {
				if(x==0) {
					turn=0;
				}
				else if(x==7) {
					turn=1;
				}
				else {
					x=0;
					s=go(y,x);
					if(s=="Done") break;
					turn=0;
				}
				continue;
			}
			
			if(i<7) break;
			if(up<=0) {
				y++;
				s=go(y,x);
				if(s=="Done") break;
			}
			turn^=1;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}