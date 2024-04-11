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

pair<ll,ll> getarg(pair<ll,ll> dx,pair<ll,ll> dy) {
	if(dx.first==0) return {0,(dy.first>0)?1:((dy.first<0)?-1:0)};
	if(dy.first==0) return {(dx.first>0)?1:-1,0};
	ll g1=__gcd(abs(dx.first),abs(dy.first));
	ll g2=__gcd(abs(dx.second),abs(dy.second));
	ll dx2=(dx.first/g1)*(dy.second/g2);
	ll dy2=(dy.first/g1)*(dx.second/g2);
	ll g=__gcd(abs(dx2),abs(dy2));
	return {dx2/g,dy2/g};
}

int N;
int A,B,C;
vector<pair<pair<ll,ll>,pair<ll,ll>>> P;
pair<ll,ll> args[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A>>B>>C;
		P.push_back({make_pair(C*A,A*A+B*B),make_pair(C*B,A*A+B*B)});
	}
	FOR(j,N) FOR(i,j) {
		pair<ll,ll> dx={P[j].first.first*P[i].first.second-P[j].first.second*P[i].first.first,P[i].first.second*P[j].first.second};
		pair<ll,ll> dy={P[j].second.first*P[i].second.second-P[j].second.second*P[i].second.first,P[i].second.second*P[j].second.second};
		args[i][j]=getarg(dx,dy);
		args[j][i]={-args[i][j].first,-args[i][j].second};
	}
	ll ret[3]={};
	FOR(i,N) {
		map<pair<ll,ll>,int> M,M2;
		int num0=0;
		FOR(j,N) if(i!=j) {
			pair<ll,ll> arg = args[i][j];
			if(arg.first==0 && arg.second==0) num0++;
			else {
				if(arg.first>0 || (arg.first==0&&arg.second>0)) M[arg]++;
				else M2[{-arg.first,-arg.second}]++;
			}
		}
		if(M2.size()<M.size()) swap(M,M2);
		FORR(r,M) ret[0] += r.second*M2[r.first];
		ret[1] += num0*(N-1-num0);
		ret[2] += num0*(num0-1)/2;
	}
	cout<<ret[0]+ret[1]/2+ret[2]/6<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}