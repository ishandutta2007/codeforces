#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int M,D;
string A,B;
ll mo=1000000007;
ll p10[2020];
ll memo[2020][2020];

string decdec(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r!='0') {
			r--;
			break;
		}
		r='9';
	}
	if(A.back()=='0') A.resize(A.size()-1);
	reverse(A.begin(),A.end());
	return A;
}

ll dodo(string S) {
	int L=S.size();
	int i,j,x;
	ll ret=0;
	int r=0;
	FOR(i,L) {
		if(i%2==0) {
			FOR(x,S[i]-'0') {
				if(i==0 && x==0) continue;
				if(x==D) continue;
				int r2=(r+x*p10[L-1-i])%M;
				ret += memo[L-1-i][(M-r2)%M];
			}
			if(S[i]-'0'==D) break;
			r+=(S[i]-'0')*p10[L-1-i];
			r%=M;
			
		}
		else {
			if(S[i]-'0'>D) {
				r+=D*p10[L-1-i];
				r%=M;
				ret+=memo[L-1-i][(M-r)%M];
				break;
			}
			else if(S[i]-'0'==D) {
				r+=D*p10[L-1-i];
				r%=M;
			}
			else {
				break;
			}
			
		}
		ret%=mo;
	}
	if(i==L&&r==0) ret++;
	return ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>D;
	cin>>A>>B;
	if(A.size()<=2) {
		x=atoi(A.c_str());
		y=atoi(B.c_str());
		r=0;
		if(A.size()==1) {
			for(i=x;i<=y;i++) if(i!=D && i%M==0) r++;
		}
		else {
			for(i=x;i<=y;i++) if(i%10==D && i/10!=D && i%M==0) r++;
		}
		cout<<r<<endl;
		return;
	}
	
	ll ret=0;
	if(!(A[0]=='1' && count(ALL(A),'0')==A.size()-1)) A=decdec(A);
	
	p10[0]=1%M;
	FOR(i,2010) p10[i+1]=p10[i]*10%M;
	
	memo[0][0]++;
	for(j=1;j<=2002;j++) {
		FOR(x,M) {
			FOR(i,10) {
				if((A.size()-j)%2==1 && i!=D) continue;
				if((A.size()-j)%2==0 && i==D) continue;
				int v=i*p10[j-1];
				(memo[j][(v+x)%M] += memo[j-1][x])%=mo;
			}
		}
	}
	
	
	cout<<(mo+ret+dodo(B)-dodo(A))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}