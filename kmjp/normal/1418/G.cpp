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

int N;
int A[505050];
ll S[505050][2][2];
int num[505050];
vector<int> pos[505050];

ll P[505050][2];
const ll mo1=1000000009;
const ll mo2=1000000021;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	P[0][0]=P[0][1]=1;
	FOR(i,N) {
		P[i+1][0]=P[i][0]*((1<<20)+5)%mo1;
		P[i+1][1]=P[i][1]*((1<<20)+rand()%1000)%mo2;
	}
	
	int ma=0;
	map<pair<pair<ll,ll>,pair<ll,ll>>,int> M;
	M[{{0LL,0LL},{0LL,0LL}}]++;
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		
		S[i+1][0][0]=S[i][0][0];
		S[i+1][0][1]=S[i][0][1];
		S[i+1][1][0]=S[i][1][0];
		S[i+1][1][1]=S[i][1][1];
		
		
		if(num[x]==1) {
			(S[i+1][0][0]+=mo1-P[x][0])%=mo1;
			(S[i+1][0][1]+=mo2-P[x][1])%=mo2;
		}
		if(num[x]==2) {
			(S[i+1][1][0]+=mo1-P[x][0])%=mo1;
			(S[i+1][1][1]+=mo2-P[x][1])%=mo2;
		}
		num[x]=(num[x]+1)%3;
		if(num[x]==1) {
			(S[i+1][0][0]+=P[x][0])%=mo1;
			(S[i+1][0][1]+=P[x][1])%=mo2;
		}
		if(num[x]==2) {
			(S[i+1][1][0]+=P[x][0])%=mo1;
			(S[i+1][1][1]+=P[x][1])%=mo2;
		}
		
		if(pos[x].size()>=3) {
			y=pos[x][pos[x].size()-3];
			while(ma<y) {
				pair<pair<ll,ll>,pair<ll,ll>>  a={{S[ma][0][0],S[ma][0][1]},{S[ma][1][0],S[ma][1][1]}};
				M[a]--;
				ma++;
			}
		}
		pos[x].push_back(i+1);
		
		pair<pair<ll,ll>,pair<ll,ll>>  a={{S[i+1][0][0],S[i+1][0][1]},{S[i+1][1][0],S[i+1][1][1]}};
		ret+=M[a];
		M[a]++;
		
		
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}