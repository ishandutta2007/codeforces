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

int T;
int N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		if(N%K) {
			cout<<-1<<endl;
			continue;
		}
		
		int C[26]={};
		FORR(c,S) C[c-'a']++;
		FOR(i,26) if(C[i]%K) break;
		if(i==26) {
			cout<<S<<endl;
			continue;
		}
		for(i=N-1;i>=0;i--) {
			C[S[i]-'a']--;
			
			for(x=S[i]-'a'+1;x<26;x++) {
				C[x]++;
				int need=0;
				FOR(j,26) need+=(K-C[j]%K)%K;
				if(need<=N-1-i) {
					int left=N-1-i;
					int add[26]={};
					for(j=25;j>=0;j--) {
						add[j]=(K-C[j]%K)%K;
						left-=add[j];
					}
					add[0]+=left;
					
					S=S.substr(0,i);
					S+='a'+x;
					FOR(y,26) S+=string(add[y],'a'+y);
					cout<<S<<endl;
					break;
					
					
				}
				C[x]--;
			}
			if(x<26) break;
		}
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}