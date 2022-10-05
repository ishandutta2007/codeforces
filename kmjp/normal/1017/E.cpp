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
vector<pair<ll,ll>> A,B;
vector<pair<long double,long double>> C,D;

const ll EPS=0;
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	if(vp.size()<=2) {
		if(vp.size()>=1) res.push_back(0);
		if(vp.size()>=2 && vp[0]!=vp[1]) res.push_back(1);
		return res;
	}
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=-EPS) k--;
		res[k++]=sorted[i].second;
	}
	/* top */
	for(rb=k, i=vp.size()-2;i>=0;i--) {
		while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=-EPS) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k-1);
	return res;
}

pair<long double,long double> center(vector<pair<long double,long double>> V) {
	if(V.size()==1) return V[0];
	if(V.size()==2) return {(V[0].first+V[1].first)/2,(V[0].second+V[1].second)/2};
	
	long double dx=0,dy=0,A=0;
	int i;
	for(i=1;i<V.size()-1;i++) {
		long double cx=(V[0].first+V[i].first+V[i+1].first)/3;
		long double cy=(V[0].second+V[i].second+V[i+1].second)/3;
		
		long double cr=abs((V[i].first-V[0].first)*(V[i+1].second-V[0].second)-(V[i+1].first-V[0].first)*(V[i].second-V[0].second));
		A+=cr;
		dx+=cx*cr;
		dy+=cy*cr;
	}
	assert(A);
	return {dx/A,dy/A};
}

vector<pair<long double,long double>> hoge(vector<pair<ll,ll>> A) {
	vector<pair<long double,long double>> C;
	auto v=convex_hull(A);
	long double dx=0,dy=0;
	FORR(c,v) {
		C.push_back({A[c].first,A[c].second});
	}
	auto ce=center(C);
	FORR(c,C) c.first-=ce.first,c.second-=ce.second;
	return C;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		A.push_back({x,y});
	}
	FOR(i,M) {
		cin>>x>>y;
		B.push_back({x,y});
	}
	
	C=hoge(A);
	D=hoge(B);
	N=C.size();
	M=D.size();
	if(N!=M) return _P("NO\n");
	FOR(i,N) if(abs(hypot(C[i].first,C[i].second)-hypot(D[0].first,D[0].second))<1e-2) {
		long double deg=atan2(D[0].second,D[0].first)-atan2(C[i].second,C[i].first);
		
		FOR(j,N) {
			long double dx=C[j].first*cos(deg)-C[j].second*sin(deg);
			long double dy=C[j].first*sin(deg)+C[j].second*cos(deg);
			if(abs(dx-D[(j+N-i)%N].first)+abs(dy-D[(j+N-i)%N].second)>1e-2) break;
		}
		if(j==N) return _P("YES\n");
		
		
	}
	
	_P("NO\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}