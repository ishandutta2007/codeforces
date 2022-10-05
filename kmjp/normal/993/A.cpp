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

int AL,AR,AT,AD;
int BL,BR,BT,BD;

int C[302][302];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	AL=101,AR=-101,AT=101,AD=-101;
	BL=101,BR=-101,BT=101,BD=-101;
	FOR(i,4) {
		cin>>x>>y;
		AL=min(AL,x);
		AR=max(AR,x);
		AT=min(AT,y);
		AD=max(AD,y);
	}
	AL+=102;
	AR+=102;
	AT+=102;
	AD+=102;
	
	FOR(i,4) {
		cin>>x>>y;
		BL=min(BL,x);
		BR=max(BR,x);
		BT=min(BT,y);
		BD=max(BD,y);
	}
	BL+=102;
	BR+=102;
	BT+=102;
	BD+=102;
	BL--,BR++;
	BT--;
	BD++;
	
	for(y=AT;y<AD;y++) {
		for(x=AL;x<AR;x++) C[y][x] |= 1;
	}
	
	int w=0;
	for(y=BT;y<BD;y++) {
		int mt=(BD+BT)/2;
		if(y<mt) w++;
		else if(y>mt) w--;
		for(x=(BL+BR)/2-w;x<(BL+BR)/2+w;x++) C[y][x] |= 2;
	}
	FOR(y,300) FOR(x,300) {
		if(C[y][x]==3) return _P("YES\n");
		
	}
	_P("NO\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}