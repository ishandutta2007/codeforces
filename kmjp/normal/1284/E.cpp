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

int N;
ll X[3030],Y[3030];
ll tar[60600],tar2[60600];
ll star[60600],star2[60600];


ll sum[6060];
void solve() {
	int i,j,k,l,r,x,y;
	long double pi=atan((long double)1)*4;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	ll ret=0;
	FOR(i,N) {
		vector<long double> V;
		FOR(j,N) if(i!=j) {
			long double a=atan2((long double)Y[j]-Y[i],(long double)X[j]-X[i]);
			V.push_back(a);
			V.push_back(2*pi+a);
			V.push_back(4*pi+a);
		}
		sort(ALL(V));
		int R=0;
		FOR(j,2*(N-1)) {
			while(V[R+1]-V[j]<=pi) R++;
			tar[j]=R;
			tar2[j]=R*R;
			star[j]=tar[j];
			star2[j]=tar2[j];
			if(j) {
				star[j]+=star[j-1];
				star2[j]+=star2[j-1];
			}
		}
		FOR(j,N-1) {
			x=tar[j];
			ret+=((star2[x]-star2[j])-2*tar[j]*(star[x]-star[j])+(x-j)*tar2[j]-(star[x]-star[j])+(x-j)*tar[j])/2;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}