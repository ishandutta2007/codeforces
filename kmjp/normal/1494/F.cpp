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

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) {
		E[x].insert(y); E[y].insert(x);
	}
	
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath(int root=-1) { // 
		int fo=-1,odd=0,i,np=0;
		FOR(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		//
		if(odd!=0 && odd!=2) return false;
		if(root==-1) {
			root=odd?fo:0;
		}
		else {
			if(odd==2&&E[root].size()%2==0) return false;
		}
		dfs(root);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}

};

int N,M;
vector<pair<int,int>> V;
int path[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(path);
	FOR(i,M) {
		cin>>x>>y;
		V.push_back({x,y});
	}
	
	
	for(i=1;i<=N;i++) {
		V.push_back({i,0});
		FORR(v,V) if(v.first==i||v.second==i) {
			UndirectedEulerPath<3030> uep2;
			int C[3030]={};
			int ne=0;
			FORR(w,V) if(w.first!=i&&w.second!=i) {
				C[w.first]++;
				C[w.second]++;
				uep2.add_path(w.first,w.second);
				ne++;
			}
			vector<int> left;
			FORR(w,V) if(w.first==i||w.second==i) {
				if(w.first==0||w.second==0) continue;
				x=w.first+w.second-i;
				if(C[x]%2!=(v==w)) C[i]++,C[x]++,uep2.add_path(i,x),ne++;
				else left.push_back(x);
			}
			
			if(uep2.GetPath(i)) {
				auto p=uep2.path;
				reverse(ALL(p));
				if(left.size()) {
					p.push_back(-1);
					FORR(v,left) p.push_back(v),p.push_back(i);
				}
				
				cout<<p.size()<<endl;
				FORR(a,p) cout<<a<<" ";
				cout<<endl;
				return;
				
			}
		}
		V.pop_back();
	}
	cout<<0<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}