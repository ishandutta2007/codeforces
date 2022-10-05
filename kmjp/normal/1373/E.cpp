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


int T,N,K;


string cand[151],cand2[151];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,151) {
		j=i;
		while(j) {
			x=min(j,9);
			if(cand[i].empty()) x=min(x,8);
			cand[i]+='0'+x;
			j-=x;
		}
		reverse(ALL(cand[i]));
		
		j=i;
		while(j) {
			x=min(j,9);
			cand2[i]+='0'+x;
			j-=x;
		}
		reverse(ALL(cand2[i]));
		
	}
	
	
	cin>>T;
	while(T--) {
		//N=T/10;
		//K=T%10;
		cin>>N>>K;
		K++;
		string S(152,'9');
		int a,b,c;
		FOR(a,10) {
			int t=0;
			int up=0;
			FOR(i,K) {
				t+=(a+i)%10;
				if(a+i>=10) up++;
			}
			FOR(i,151) {
				int num=t+(i+1)*up+i*(K-up);
				
				if(num>N) continue;
				if((N-num)%(9*(K-up))) continue;
				int n9=(N-num)/9/(K-up);
				
				string T;
				if(up==0) T=cand2[i];
				else T=cand[i];
				FOR(x,n9) T+='9';
				T+=(char)('0'+a);
				if(T.size()<S.size() || (T.size()==S.size() && T<S)) S=T;
			}
		}
		if(S.size()==152) S="-1";
		//cout<<N<<" "<<(K-1)<<" ";
		cout<<S<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}