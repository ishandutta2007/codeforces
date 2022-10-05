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

int ispalin(int a,int b) {
	int c=a/10+a%10*10;
	return c==b;
}

string s;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	x=(s[0]-'0')*10+s[1]-'0';
	y=(s[3]-'0')*10+s[4]-'0';
	FOR(i,4040) {
		if(ispalin(x,y)) return _P("%d\n",i);
		y++;
		if(y==60) {
			x++;
			y=0;
			if(x==24) x=0;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}