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
vector<int> A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) A[y].resize(W);
	
	if(W>=4) {
		FOR(y,H) {
			vector<int> V;
			FOR(x,W) V.push_back(y*W+x);
			if(W%2==0) {
				if(y%2) reverse(ALL(V));
			}
			else rotate(V.begin(),V.begin()+y%W,V.end());
			FOR(x,W) A[y][x]=V[(x/2)+((x%2==0)?(W/2):0)];
		}
	}
	else if(H>=4) {
		FOR(x,W) {
			vector<int> V;
			FOR(y,H) V.push_back(y*W+x);
			if(H%2==0) {
				if(x%2) reverse(ALL(V));
			}
			else rotate(V.begin(),V.begin()+x%H,V.end());
			FOR(y,H) A[y][x]=V[(y/2)+((y%2==0)?(H/2):0)];
		}
	}
	else {
		
		int ng=0;
		vector<int> V;
		FOR(i,H*W) V.push_back(i);
		do {
			FOR(y,H) FOR(x,W) A[y][x]=V[y*W+x];
			ng=0;
			FOR(y,H) FOR(x,W) {
				if(y) {
					if(abs(A[y][x]-A[y-1][x])==W) ng++;
					if(abs(A[y][x]-A[y-1][x])==1 && A[y][x]/W==A[y-1][x]/W) ng++;
				}
				if(x) {
					if(abs(A[y][x]-A[y][x-1])==W) ng++;
					if(abs(A[y][x]-A[y][x-1])==1 && A[y][x]/W==A[y][x-1]/W) ng++;
				}
			}
			if(ng==0) break;
			
		} while(next_permutation(ALL(V)));
		if(ng) return _P("NO\n");
	}
	
	/*
	int ng=0;
	FOR(y,H) FOR(x,W) {
		if(y) {
			if(abs(A[y][x]-A[y-1][x])==W) ng++;
			if(abs(A[y][x]-A[y-1][x])==1 && A[y][x]/W==A[y-1][x]/W) ng++;
		}
		if(x) {
			if(abs(A[y][x]-A[y][x-1])==W) ng++;
			if(abs(A[y][x]-A[y][x-1])==1 && A[y][x]/W==A[y][x-1]/W) ng++;
		}
	}
	cout<<ng<<endl;
	*/
	
	_P("YES\n");
	FOR(y,H) {
		FOR(x,W) _P("%d%c",A[y][x]+1,(x==W-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}