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

int T;
int C[2][3];
int num[8];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,2) cin>>C[i][2]>>C[i][1]>>C[i][0];
		FOR(i,7) cin>>num[7-i];
		
		int XL=max(0,num[7]+num[6]+num[5]+num[4]-C[1][2]);
		int YL=max(0,num[7]+num[6]+num[3]+num[2]-C[1][1]);
		int ZL=max(0,num[7]+num[5]+num[3]+num[1]-C[1][0]);
		int XR=min(num[7]+num[6]+num[5]+num[4],C[0][2]);
		int YR=min(num[7]+num[6]+num[3]+num[2],C[0][1]);
		int ZR=min(num[7]+num[5]+num[3]+num[1],C[0][0]);
		
		int ok=0;
		for(int f6=0;f6<=min(XR,num[6]);f6++) {
			for(int f5=0;f5<=num[5]&&f6+f5<=XR;f5++) {
				for(int f3=0;f3<=num[3]&&f6+f3<=YR && f5+f3<=ZR;f3++) {
					int x=f6+f5;
					int y=f6+f3;
					int z=f5+f3;
					int f7=max(0,min({num[7],XR-x,YR-y,ZR-z}));
					x+=f7;
					y+=f7;
					z+=f7;
					int f4=max(0,min(num[4],XR-x));
					int f2=max(0,min(num[2],YR-y));
					int f1=max(0,min(num[1],ZR-z));
					x+=f4;
					y+=f2;
					z+=f1;
					
					if(x>=XL && x<=XR && y>=YL&&y<=YR&&z>=ZL&&z<=ZR) {
						ok=1;
						cout<<f7<<" "<<f6<<" "<<f5<<" "<<f4<<" "<<f3<<" "<<f2<<" "<<f1<<endl;
						f5=f6=101010;
						break;
						
					}
					
				}
			}
		}
		if(ok==0) {
			cout<<-1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}