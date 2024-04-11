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

int NV=1<<19;
vector<pair<double,double>> pos;
vector<int> len;
vector<int> deg;
double pi;
int N,M;

pair<double,double> rot(pair<double,double> p,int d) {
	double c=cos(d/180.0*pi);
	double s=sin(d/180.0*pi);
	return {p.first*c-p.second*s,p.first*s+p.second*c};
}

void update(int entry, int L,int D) {
	len[entry]+=L;
	entry += NV;
	deg[entry]-=D;
	pos[entry]=rot({len[entry-NV],0},deg[entry]);
	
	while(entry>1) {
		entry>>=1;
		deg[entry]=deg[entry*2]+deg[entry*2+1];
		auto r=rot(pos[entry*2+1],deg[entry*2]);
		pos[entry]={r.first+pos[entry*2].first,r.second+pos[entry*2].second};
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	pi=atan(1)*4;
	len.resize(NV);
	pos.resize(NV*2);
	deg.resize(NV*2);
	
	cin>>N>>M;
	FOR(i,N) update(i,1,0);
	FOR(i,M) {
		cin>>j>>x>>y;
		if(j==1) update(x-1,y,0);
		if(j==2) update(x-1,0,y);
		_P("%.12lf %.12lf\n",pos[1].first,pos[1].second);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}