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
int H,W,K;
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		
		FOR(y,H) S[y]=string(W,'.');
		
		if(H%2==0&&W%2==0) {
			ok:
			for(y=0;y+1<H;y+=2) {
				for(x=0;x+1<W;x+=2) {
					int c=(y+x*4)%16;
					if(K) {
						K-=2;
						S[y][x]='a'+c;
						S[y][x+1]='a'+c;
						S[y+1][x]='a'+c+1;
						S[y+1][x+1]='a'+c+1;
					}
					else {
						S[y][x]='a'+c;
						S[y][x+1]='a'+c+1;
						S[y+1][x]='a'+c;
						S[y+1][x+1]='a'+c+1;
					}
				}
			}
		}
		else if(H%2==0) {
			for(y=0;y<H;y+=2) {
				for(x=0;x+1<W;x+=2) {
					int c=(y+x*4)%16;
					if(K) {
						K-=2;
						S[y][x]='a'+c;
						S[y][x+1]='a'+c;
						S[y+1][x]='a'+c+1;
						S[y+1][x+1]='a'+c+1;
					}
					else {
						S[y][x]='a'+c;
						S[y][x+1]='a'+c+1;
						S[y+1][x]='a'+c;
						S[y+1][x+1]='a'+c+1;
					}
				}
			}
			for(y=0;y<H;y+=2) {
				x=W-1;
				int c=(y+x*4)%16;
				S[y][x]='a'+c;
				S[y+1][x]='a'+c;
			}
		}
		else {
			for(x=0;x<W;x+=2) {
				K--;
				y=H-1;
				int c=(y+x*4)%16;
				S[y][x]='a'+c;
				S[y][x+1]='a'+c;
			}
			goto ok;
		}
		if(K) {
			cout<<"NO"<<endl;
			continue;
		}
		
		cout<<"YES"<<endl;
		//FOR(y,H) cout<<S[y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}