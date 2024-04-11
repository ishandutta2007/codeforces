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
int TH,TW;
string S[404];
string T[404];

bitset<170000> B[26];
bitset<170000> R,R2,mask,lef[401],ri[401];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			B[S[y][x]-'a'][y*W+x]=1;
			R[y*W+x]=1;
		}
	}
	lef[0]=R2=R;
	for(x=1;x<=W;x++) {
		lef[x]=lef[x-1];
		FOR(y,H) lef[x][y*W+W-x]=0;
		ri[x]=(~lef[x]) & R;
	}
	
	mask=~R;
	
	cin>>TH>>TW;
	FOR(y,TH) {
		cin>>T[y];
		FOR(x,TW) if(T[y][x]!='?') {
			r=T[y][x]-'a';
			int yy=y%H;
			int xx=x%W;
			// up y
			bitset<170000> BT=((B[r]>>(yy*W)) | (B[r]<<(W*H-(yy*W))))&R2;
			// left x
			R &= ((BT>>(xx))&lef[xx]) | ((BT<<(W-xx))&ri[xx]);
		}
	}
	
	FOR(y,H) {
		FOR(x,W) _P("%d",R[y*W+x]==1);
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}