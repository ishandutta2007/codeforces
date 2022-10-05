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

int T,N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int mi=1<<20;
		int pre=-1;
		FOR(i,N) if(S[i]=='a') {
			if(pre>=0) {
				int C[2]={};
				for(j=pre+1;j<i;j++) {
					C[S[j]-'b']++;
				}
				if(C[0]<=1&&C[1]<=1) mi=min(mi,i-pre+1);
			}
			pre=i;
		}
		{
			int pre[2]={-1,-1};
			FOR(i,N) if(S[i]=='a') {
				if(pre[0]>=0) {
					int C[2]={};
					for(j=pre[0]+1;j<i;j++) {
						if(S[j]!='a') C[S[j]-'b']++;
					}
					if(C[0]<=2&&C[1]<=2) mi=min(mi,i-pre[0]+1);
				}
				pre[0]=pre[1];
				pre[1]=i;
			}
		}
		
		if(mi==1<<20) mi=-1;
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}