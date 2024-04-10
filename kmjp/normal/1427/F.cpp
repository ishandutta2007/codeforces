#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int pat[2020];
vector<vector<int>> cand[2];
int root[2020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=6*N;i++) {
		pat[i]=root[i]=1;
		bt.add(i,1);
	}
	FOR(i,3*N) {
		cin>>x;
		pat[x]=0;
	}
	
	vector<int> V;
	for(i=1;i<=6*N;i++) {
		if(V.size()>=2 && pat[V[V.size()-2]]==pat[i]&&pat[V[V.size()-1]]==pat[i]) {
			for(x=V[V.size()-2]+1;x<i;x++) root[x]=0;
			cand[pat[i]].push_back({V[V.size()-2],V[V.size()-1],i});
			V.pop_back();
			V.pop_back();
			
		}
		else {
			V.push_back(i);
		}
	}
	assert(V.empty());
	
	vector<vector<int>> R;
	FOR(i,N) {
		FOR(x,2) {
			y=0;
			FORR(c,cand[x]) {
				if(bt(c[0])-bt(c[0]-1)==0) continue;
				if(bt(c[1])-bt(c[1]-1)==0) continue;
				if(bt(c[2])-bt(c[2]-1)==0) continue;
				if(bt(c[2])-bt(c[0]-1)!=3) continue;
				if(x==1&&root[c[0]]) continue;
				R.push_back(c);
				bt.add(c[0],-1);
				bt.add(c[1],-1);
				bt.add(c[2],-1);
				y=1;
				break;
			}
			if(y==0) {
				FORR(c,cand[x]) {
					if(bt(c[0])-bt(c[0]-1)==0) continue;
					if(bt(c[1])-bt(c[1]-1)==0) continue;
					if(bt(c[2])-bt(c[2]-1)==0) continue;
					if(bt(c[1])-bt(c[0])!=1) continue;
					if(bt(c[2])-bt(c[0]-1)!=3) continue;
					R.push_back(c);
					bt.add(c[0],-1);
					bt.add(c[1],-1);
					bt.add(c[2],-1);
					break;
				}
			}
		}
	}
	
	FORR(r,R) cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}