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


int N;
multiset<int> E[602020];
vector<vector<pair<int,int>>> C;
vector<vector<pair<int,int>>> cand;

pair<int,int> dfs(int cur,pair<int,int> par) {
	pair<int,int> oth={0,0};
	while(E[cur].size()) {
		int e=*E[cur].begin();
		E[cur].erase(E[cur].find(e));
		E[e].erase(E[e].find(cur));
		auto p=dfs(e,{cur,e});
		if(p.first) {
			if(oth.first) {
				cand.push_back({p,oth});
				oth={0,0};
			}
			else {
				oth=p;
			}
		}
	}
	if(oth.first) {
		if(par.first) {
			cand.push_back({par,oth});
			return {0,0};
		}
		else {
			return oth;
		}
	}
	else return par;
		
	
}

vector<pair<int,int>> ret;
vector<string> P1;
vector<string> P2;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		E[x].insert(y);
		E[y].insert(x);
	}
	
	for(i=1;i<=2*N;i++) if(E[i].size()) {
		cand.clear();
		auto p=dfs(i,{0,0});
		if(cand.empty()) {
			cout<<-1<<endl;
			return;
		}
		if(p.first) {
			cand.back().push_back(p);
		}
		FORR(c,cand) C.push_back(c);
	}
	
	FORR(c,C) {
		if(c.size()==2) {
			auto p1=c[0];
			auto p2=c[1];
			if(p1.first==p2.second) swap(p2.first,p2.second);
			if(p1.second==p2.second) swap(p2.first,p2.second),swap(p1.first,p1.second);
			if(p1.second==p2.first) swap(p1.first,p1.second);
			ret.push_back({p1.first,p1.second});
			ret.push_back({p2.second,p2.first});
			P1.push_back("LR");
			P1.push_back("LR");
			P2.push_back("UU");
			P2.push_back("DD");
		}
		else {
			int add=0;
			sort(ALL(c));
			do {
				auto p1=c[0];
				auto p2=c[1];
				auto p3=c[2];
				FOR(x,8) {
					if((x&1)==1) swap(p1.first,p1.second);
					if(x==2||x==6) swap(p2.first,p2.second);
					if(x==4) swap(p3.first,p3.second);
					if(p1.first==p2.first&&p1.first==p3.first) {
						ret.push_back({p1.first,p1.second});
						ret.push_back({p2.second,p2.first});
						ret.push_back({p3.first,p3.second});
					}
					else if(p1.second==p2.first&&p2.second==p3.first) {
						ret.push_back({p1.first,p1.second});
						ret.push_back({p2.first,p2.second});
						ret.push_back({p3.first,p3.second});
					}
					else {
						continue;
					}
					P1.push_back("LR");
					P1.push_back("UU");
					P1.push_back("DD");
					P2.push_back("UU");
					P2.push_back("DD");
					P2.push_back("LR");
					add++;
					break;
				}
				if(add) break;
			} while(next_permutation(ALL(c)));
			
			if(add==0) {
				FORR(a,c) cout<<a.first<<" "<<a.second<<endl;
				assert(0);
			}
		}
	}
	cout<<N<<" "<<2<<endl;
	FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
	FORR(s,P1) cout<<s<<endl;
	FORR(s,P2) cout<<s<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}