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

int N;
ll S;
ll ma=0;
int id[3];
vector<pair<ll,ll>> P,R;

ll area(int a,int b,int c) {
	ll bx=P[b].first-P[a].first;
	ll by=P[b].second-P[a].second;
	ll cx=P[c].first-P[a].first;
	ll cy=P[c].second-P[a].second;
	return abs(bx*cy-by*cx);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		cin>>x>>y;
		R.push_back({x,y});
	}
	auto VV=convex_hull(R);
	FORR(r,VV) P.push_back(R[r]);
	N=P.size();
	for(i=0;i<N;i++) {
		for(j=i+1,k=j+1;j<N;j++) {
			k=min(N-1,max(j,k));
			while(k+1<N && area(i,j,k+1)>=area(i,j,k)) k++;
			if(area(i,j,k)>ma) {
				ma=area(i,j,k);
				id[0]=i;
				id[1]=j;
				id[2]=k;
			}
		}
	}
	
	cout<<(P[id[0]].first+P[id[2]].first-P[id[1]].first)<<" "<<(P[id[0]].second+P[id[2]].second-P[id[1]].second)<<endl;
	cout<<(P[id[1]].first+P[id[2]].first-P[id[0]].first)<<" "<<(P[id[1]].second+P[id[2]].second-P[id[0]].second)<<endl;
	cout<<(P[id[0]].first+P[id[1]].first-P[id[2]].first)<<" "<<(P[id[0]].second+P[id[1]].second-P[id[2]].second)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}