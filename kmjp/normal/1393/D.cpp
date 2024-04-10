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
string S[3030];
int step[2020][2020];
int num[2020][2020];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(i,26) {
		ZERO(step);
		ZERO(num);
		FOR(y,H+4) FOR(x,W+4) {
			step[y+2][x+2]=step[y+1][x+1]+step[y+1][x+3]-step[y][x+2];
			if(y<H&&x<W&&S[y][x]=='a'+i) step[y+2][x+2]++;
		}
	
		FOR(y,H) {
			FOR(x,W) if(S[y][x]-'a'==i) {
				int len=1;
				for(j=10;j>=0;j--) {
					int tlen=len+(1<<j);
					if(y>=(tlen-1)*2&&x>=tlen-1&&x+tlen-1<W) {
						int a=step[y+2][x+2]-step[y+2-tlen][x+2-tlen]-step[y+2-tlen][x+2+tlen]+step[y+2-(tlen)*2][x+2];
						if(a==tlen*tlen) len=tlen;
					}
				}
				num[y][x]=len;
				if(y&&S[y][x]==S[y-1][x]) len=min(len,num[y-1][x]+1);
				else len=1;
				ret+=len;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}