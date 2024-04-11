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

int N,M;
string A[505050],B[505050],C[505050],D[505050];
string V[2];
char TV[2][505050];
unordered_map<string,int> mp;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>s;
	FOR(i,N) {
		A[i]=s;
		mp[A[i]]=i;
		cin>>s>>B[i];
		cin>>s;
		if(s=="XOR" || s=="OR" || s=="AND") {
			C[i]=s;
			cin>>D[i]>>s;
		}
		else {
			C[i]="AND";
			D[i]=B[i];
		}
	}
	
	FOR(i,M) {
		int cnt[2]={};
		
		FOR(j,2) {
			char c=j;
			FOR(x,N) {
				char l,r;
				if(B[x][0]=='?') l=c;
				else if(B[x][0]=='0' || B[x][0]=='1') l=B[x][i]-'0';
				else l=TV[j][mp[B[x]]]-'0';
				
				if(D[x][0]=='?') r=c;
				else if(D[x][0]=='0' || D[x][0]=='1') r=D[x][i]-'0';
				else r=TV[j][mp[D[x]]]-'0';
				
				if(C[x]=="AND") TV[j][x]=(l&r)+'0';
				if(C[x]=="OR")  TV[j][x]=(l|r)+'0';
				if(C[x]=="XOR") TV[j][x]=(l^r)+'0';
				if(TV[j][x]=='1') cnt[j]++;
			}
		}
		V[0]+='0'+(cnt[0]>cnt[1]);
		V[1]+='0'+(cnt[0]<cnt[1]);
	}
	cout<<V[0]<<endl;
	cout<<V[1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}