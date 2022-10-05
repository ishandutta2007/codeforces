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

ll bt[404040];

vector<double> V;
int S,A,B;
int N,Q;

double hoge(double X) {
	int x=lower_bound(ALL(V),X)-V.begin();
	x--;
	if(x<0) return 0;
	if(x>=2*N-1) return bt[x];
	double ret=bt[x];
	if(x%2==0) ret+=X-V[x];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&S,&A,&B);
	scanf("%d",&N);
	ll sum=0;
	FOR(i,N) {
		scanf("%d%d",&x,&y);
		V.push_back(x);
		V.push_back(y);
		bt[2*i]=sum;
		sum+=y-x;
		bt[2*i+1]=sum;
	}
	
	scanf("%d",&Q);
	while(Q--) {
		double X,Y,L,R;
		scanf("%d%d",&x,&y);
		X=x;
		Y=y;
		L=A+1.0*(X-A)*(-S)/(Y-S);
		R=B+1.0*(X-B)*(-S)/(Y-S);
		X=hoge(R)-hoge(L);
		
		_P("%.12lf\n",X/Y*(Y-S));
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}