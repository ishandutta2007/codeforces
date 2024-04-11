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


int subsub(int l,int s,string& S) {
	while(s) {
		if(l>=S.size()) return 0;
		S[l]-=s;
		if(S[l]>=0) break;
		S[l]+=10;
		s=1;
		l++;
	}
	return 1;
}

string trytry(int L,string S) {
	int i,j;
	string R=string(L,'0');
	
	FOR(i,(L+1)/2) {
		if(L%2 && i==L/2) {
			if(S[i]%2) return "";
			R[i]+=S[i]/2;
			S[i]=0;
			if(S[i+1]==1) S[i+1]=0, R[i]+=5;
		}
		else {
			int low=S[i];
			
			if(subsub(L-1-i,low,S)==0) return "";
			
			int hi=S[L-1-i+1];
			int sum=hi*10+low;
			if(sum>18) return "";
			
			S[i]=S[L-1-i+1]=0;
			if(subsub(i+1,hi,S)==0) return "";
			
			R[i]+=min(9,sum);
			R[L-1-i]+=sum-(R[i]-'0');
		}
	}
	
	if(R[0]=='0' || count(ALL(S),0)!=S.size()) return "";
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	string S;
	cin>>S;
	int L=S.size();
	
	reverse(ALL(S));
	S+='0';
	FORR(c,S) c-='0';
	
	s=trytry(L,S);
	if(s=="" && L>1) s=trytry(L-1,S);
	if(s!="") cout<<s<<endl;
	else cout<<0<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}