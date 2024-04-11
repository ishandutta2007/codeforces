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
ll X[2020],Y[2020];
int avail[2020];

int check(ll sx,ll sy) {
	vector<pair<ll,ll>> V;
	int i;
	FOR(i,N) {
		ll x=(sy==0)?0:(X[i]*sy-sx*Y[i]);
		ll y=(sx==0)?0:(sx*Y[i]-X[i]*sy);
		V.push_back({x,y});
	}
	sort(ALL(V));
	int L=0,R=V.size()-1;
	while(L<=R) {
		if(V[L].first!=-V[R].first || V[L].second!=-V[R].second) return 0;
		L++;
		R--;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll SX=0,SY=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]*=2*N;
		Y[i]*=2*N;
		SX+=X[i];
		SY+=Y[i];
	}
	SX/=N;
	SY/=N;
	FOR(i,N) X[i]-=SX,Y[i]-=SY,avail[i]=1;
	FOR(x,N) if(avail[x]) {
		FOR(y,N) if(avail[y]) {
			if(X[x]+X[y]==0 && Y[x]+Y[y]==0) {
				avail[x]=avail[y]=0;
				break;
			}
		}
	}
	vector<pair<ll,ll>> V;
	FOR(i,N) if(avail[i]) V.push_back({X[i],Y[i]});
	FOR(i,V.size()) X[i]=V[i].first,Y[i]=V[i].second;
	N=V.size();
	
	if(N==0) return _P("-1\n");
	
	vector<pair<ll,ll>> cand;
	FOR(y,N) FOR(x,N) {
		ll sx=(X[x]+X[y])/2;
		ll sy=(Y[x]+Y[y])/2;
		ll g=__gcd(abs(sx),abs(sy));
		sx/=g;
		sy/=g;
		if(sx<0) sx=-sx, sy=-sy;
		if(sx==0 && sy<0) sy=-sy;
		cand.push_back({sx,sy});
	}
	
	int ret=0;
	sort(ALL(cand));
	pair<ll,ll> pre={0,0};
	int cnt=0;
	FORR(r,cand) {
		if(pre!=r) pre=r, cnt=0;
		cnt++;
		if(cnt==N) ret+=check(r.first,r.second);
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}