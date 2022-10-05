#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,S;
vector<ll> dif(1);
vector<multiset<ll>> ms(1);
vector<map<int,ll>> mi(1);


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	ms.back().insert(0);
	mi.back()[0]=0;
	while(N--) {
		cin>>s;
		if(s=="set") {
			cin>>x>>y;
			
			if(ms.back().empty()) continue;
			
			if(x==S) {
				dif.back()+=y;
			}
			else {
				ll cand=dif.back()+*ms.back().begin();
				if(mi.back().count(x)) {
					ms.back().erase(ms.back().find(mi.back()[x]));
				}
				dif.back()+=y;
				mi.back()[x]=cand-dif.back();
				ms.back().insert(mi.back()[x]);
			}
		}
		else if(s=="if") {
			cin>>x;
			if(mi.back().count(x)) {
				ll sc=mi.back()[x];
				ms.back().erase(ms.back().find(sc));
				mi.back().erase(x);
				mi.push_back(map<int,ll>());
				ms.push_back(multiset<ll>());
				mi.back()[x]=sc+dif.back();
				ms.back().insert(sc+dif.back());
				dif.push_back(0);
			}
			else {
				dif.push_back(0);
				mi.push_back(map<int,ll>());
				ms.push_back(multiset<ll>());
			}
		}
		else {
			x=mi.size();
			if(mi[x-1].size()>mi[x-2].size()) {
				swap(dif[x-2],dif[x-1]);
				swap(mi[x-2],mi[x-1]);
				swap(ms[x-2],ms[x-1]);
			}
			FORR2(k,v,mi[x-1]) {
				if(mi[x-2].count(k)) {
					ms[x-2].erase(ms[x-2].find(mi[x-2][k]));
					mi[x-2][k]=min(mi[x-2][k],dif[x-1]+v-dif[x-2]);
				}
				else {
					mi[x-2][k]=dif[x-1]+v-dif[x-2];
				}
				
				ms[x-2].insert(mi[x-2][k]);
			}
			dif.pop_back();
			mi.pop_back();
			ms.pop_back();
		}
	}
	ll ret=1LL<<60;
	FORR(d,mi[0]) ret=min(ret,d.second+dif[0]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}