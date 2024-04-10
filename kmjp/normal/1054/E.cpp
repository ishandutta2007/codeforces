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

int H,W;
string S[1010][1010];
string T[1010][1010];
//deque<char> D[1010][1010];
int C[2][1919];
vector<vector<int>> R;

void add(int y1,int x1,int y2,int x2) {
	if(y1==y2 && x1==x2) return;
	assert(y1!=y2 || x1!=x2);
	R.push_back({y1+1,x1+1,y2+1,x2+1});
	//char c=D[y1][x1].back();
	//D[y1][x1].pop_back();
	//D[y2][x2].push_front(c);
	
}

/*
void debug() {
	int y,x;
	FOR(y,H) {
		FOR(x,W) {
			string s;
			FORR(c,D[y][x]) s.push_back(c);
			cout<<s<<" ";
		}
		cout<<endl;
	}
}
*/
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>S[y][x];
		//FORR(c,S[y][x]) D[y][x].push_back(c);
	}
	
	FOR(y,H) FOR(x,W) {
		reverse(ALL(S[y][x]));
		FORR(c,S[y][x]) {
			if(c=='0') {
				if(x==0) {
					C[0][(y+1)%H]++;
					add(y,x,(y+1)%H,0);
				}
				else {
					C[0][y]++;
					add(y,x,y,0);
				}
			}
			else {
				if(x==W-1) {
					C[1][(y+1)%H]++;
					add(y,x,(y+1)%H,W-1);
				}
				else {
					C[1][y]++;
					add(y,x,y,W-1);
				}
			}
		}
	}
	
	FOR(y,H) {
		if(y) FOR(i,C[0][y]) add(y,0,0,0);
		if(y!=H-1) FOR(i,C[1][y]) add(y,W-1,H-1,W-1);
	}
	FOR(y,H) FOR(x,W) {
		cin>>T[y][x];
		reverse(ALL(T[y][x]));
		if(x>0 && y<H-1) {
			FORR(c,T[y][x]) {
				if(c=='0') {
					add(0,0,y,0);
					add(y,0,y,x);
				}
				else {
					add(H-1,W-1,H-1,x);
					add(H-1,x,y,x);
				}
			}
		}
	}
	
	for(y=1;y<H-1;y++) {
		x=0;
		FORR(c,T[y][x]) {
			if(c=='0') {
				add(0,0,y,0);
				add(y,0,y,x);
			}
			else {
				add(H-1,W-1,H-1,x);
				add(H-1,x,y,x);
			}
		}
	}
	for(x=1;x<W-1;x++) {
		y=H-1;
		FORR(c,T[y][x]) {
			if(c=='0') {
				add(0,0,y,0);
				add(y,0,y,x);
			}
			else {
				add(H-1,W-1,H-1,x);
				add(H-1,x,y,x);
			}
		}
	}
	
	FOR(i,3) {
		if(i==0) y=H-1,x=W-1;
		if(i==1) y=0,x=0;
		if(i==2) y=H-1,x=0;
		FORR(c,T[y][x]) {
			if(c=='0') add(0,0,H-1,0);
			else add(H-1,W-1,H-1,0);
		}
	}
	FOR(i,2) {
		if(i==0) y=H-1,x=W-1;
		if(i==1) y=0,x=0;
		FOR(j,T[y][x].size()) add(H-1,0,y,x);
	}
	
	_P("%d\n",R.size());
	FORR(r,R) {
		_P("%d %d %d %d\n",r[0],r[1],r[2],r[3]);
	}
	/*
	
	FOR(y,H) {
		FOR(x,W) {
			string s;
			FORR(c,D[y][x]) s.push_back(c);
			reverse(ALL(T[y][x]));
			assert(s==T[y][x]);
		}
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}