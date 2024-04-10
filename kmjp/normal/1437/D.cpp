#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
int A[202020];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int d=1;
		int num,tnum,pre;
		int last;
		FOR(i,N) {
			cin>>x;
			if(i==0) {
				d=2;
				num=1;
				tnum=0;
				last=0;
			}
			else if(last==0) {
				num--;
				tnum++;
				last=x;
			}
			else {
				if(x>last) {
					tnum++;
					last=x;
				}
				else {
					if(num) {
						num--;
						tnum++;
						last=x;
					}
					else {
						d++;
						num=tnum-1;
						tnum=1;
						last=x;
					}
				}
			}
			
		}
		
		cout<<d-1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}