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
int N;
string S;
int C[26];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,26) C[i]=0;
		FORR(c,S) C[c-'a']++;
		FOR(i,26) if(C[i]==1) {
			string R;
			R+='a'+i;
			FOR(j,26) if(i!=j) R+=string(C[j],'a'+j);
			cout<<R<<endl;
			break;
		}
		if(i<26) continue;
		FOR(i,26) if(C[i]==N) {
			cout<<S<<endl;
			break;
		}
		if(i<26) continue;
		
		vector<int> cand;
		FOR(i,26) if(C[i]) cand.push_back(i);
		int can=0;
		FOR(i,N) if(i==0||i%2==1) can++;
		string R;
		if(C[cand[0]]<=can) {
			R.resize(N);
			FOR(i,N) if((i==0||i%2==1)&&C[cand[0]]) {
				C[cand[0]]--;
				R[i]='a'+cand[0];
			}
			FOR(i,N) if(R[i]==0) {
				FOR(j,26) if(C[j]) {
					C[j]--;
					R[i]='a'+j;
					break;
				}
			}
		}
		else {
			if(cand.size()>=3) {
				R="";
				R+='a'+cand[0];
				R+='a'+cand[1];
				C[cand[0]]--;
				C[cand[1]]--;
				FOR(i,C[cand[0]]) R+='a'+cand[0];
				C[cand[0]]=0;
				R+='a'+cand[2];
				C[cand[2]]--;
				FOR(j,26) R+=string(C[j],'a'+j);
			}
			else {
				R=string(1,'a'+cand[0])+string(C[cand[1]],'a'+cand[1])+string(C[cand[0]]-1,'a'+cand[0]);
			}
			
		}
		cout<<R<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}