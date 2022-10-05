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
string S[1010];
int SY,SX,TY,TX;

int LR[1010][1010];
int UD[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') {
				S[y][x]='.';
				SY=y;
				SX=x;
			}
			if(S[y][x]=='T') {
				S[y][x]='.';
				TY=y;
				TX=x;
			}
			LR[y][x+1]=LR[y][x]+(S[y][x]=='*');
			UD[y+1][x]=UD[y][x]+(S[y][x]=='*');
		}
	}
	
	vector<pair<int,int>> CS,CT;
	FOR(x,W) if(LR[SY][max(x,SX)+1]==LR[SY][min(x,SX)]) CS.push_back({SY,x});
	FOR(x,W) if(LR[TY][max(x,TX)+1]==LR[TY][min(x,TX)]) CT.push_back({TY,x});
	FOR(y,H) if(UD[max(y,SY)+1][SX]==UD[min(y,SY)][SX]) CS.push_back({y,SX});
	FOR(y,H) if(UD[max(y,TY)+1][TX]==UD[min(y,TY)][TX]) CT.push_back({y,TX});
	FORR(s,CS) FORR(t,CT) {
		if(s==t) return _P("YES\n");
		if(s.first==t.first && LR[s.first][max(s.second,t.second)+1]==LR[t.first][min(s.second,t.second)]) return _P("YES\n");
		if(s.second==t.second && UD[max(s.first,t.first)+1][s.second]==UD[min(s.first,t.first)][t.second]) return _P("YES\n");
	}
	_P("NO\n");
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}