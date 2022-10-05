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
ll S[303030],T[303030];
ll D;
pair<ll,int> P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		D+=S[i];
		P[i]={S[i],i};
	}
	FOR(i,N) cin>>T[i], D-=T[i];
	sort(T,T+N);
	if(D) {
		cout<<"NO"<<endl;
		return;
	}
	sort(P,P+N);
	vector<int> R;
	set<pair<int,int>> L;
	FOR(i,N) {
		if(P[i].first>T[i]) L.insert({P[i].first,i});
		if(P[i].first<T[i]) R.push_back(i);
	}
	vector<vector<int>> ret;
	reverse(ALL(R));
	FORR(r,R) {
		
		while(P[r].first<T[r]) {
			auto it=L.lower_bound({P[r].first+1,0});
			if(it==L.end()) {
				cout<<"NO"<<endl;
				return;
			}
			x=it->second;
			L.erase(it);
			ll mi=min({T[r]-P[r].first,P[x].first-T[x],(P[x].first-P[r].first)/2});
			ret.push_back({P[r].second+1,P[x].second+1,(int)mi});
			P[r].first+=mi;
			P[x].first-=mi;
			
			if(P[x].first!=T[x]) L.insert({P[x].first,x});
		}
	}
	
	_P("YES\n");
	_P("%d\n",ret.size());
	FORR(r,ret) {
		_P("%d %d %d\n",r[0],r[1],r[2]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}