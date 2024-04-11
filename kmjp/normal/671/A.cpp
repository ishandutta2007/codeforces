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

ll AX,AY,BX,BY,TX,TY;
int N;
double R[3][101010];
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>AX>>AY>>BX>>BY>>TX>>TY;
	AX-=TX;
	AY-=TY;
	BX-=TX;
	BY-=TY;
	
	cin>>N;
	double tot=0;
	vector<pair<double,int>> V[2];
	FOR(i,N) {
		cin>>X[i]>>Y[i], X[i]-=TX, Y[i]-=TY;
		R[0][i]=2*sqrt(X[i]*X[i]+Y[i]*Y[i]);
		R[1][i]=sqrt(X[i]*X[i]+Y[i]*Y[i]) + sqrt((X[i]-AX)*(X[i]-AX)+(Y[i]-AY)*(Y[i]-AY));
		R[2][i]=sqrt(X[i]*X[i]+Y[i]*Y[i]) + sqrt((X[i]-BX)*(X[i]-BX)+(Y[i]-BY)*(Y[i]-BY));
		V[0].push_back({R[1][i]-R[0][i],i});
		V[1].push_back({R[2][i]-R[0][i],i});
		tot += R[0][i];
	}
	double ret=1e50;
	sort(ALL(V[0]));
	sort(ALL(V[1]));
	
	// take one
	FOR(i,N) {
		ret = min(ret,tot-R[0][i]+R[1][i]);
		ret = min(ret,tot-R[0][i]+R[2][i]);
	}
	
	FOR(x,min(4,N)) {
		FOR(y,min(4,N)) {
			if(V[0][x].second!=V[1][y].second) {
				ret = min(ret,tot+V[0][x].first+V[1][y].first);
			}
		}
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}