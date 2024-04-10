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
vector<pair<int,int>> V[10101];

vector<pair<int,int>> add[10101];
vector<int> del[10101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,14> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1+=5001;
		y1+=5001;
		x2+=5001;
		y2+=5001;
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		
		if(x1==x2) V[x1].push_back({y1,y2});
		else add[x1].push_back({y1,x2});
	}
	ll ret=0;
	FOR(x,10002) FORR(v,V[x]) {
		for(i=0;i<=10002;i++) del[i].clear();
		for(i=0;i<=x;i++) {
			FORR(a,add[i]) {
				bt.add(a.first,1);
				del[a.second].push_back(a.first);
			}
			FORR(a,del[i]) bt.add(a,-1);
		}
		for(i=x+1;i<=10002;i++) {
			FORR(vv,V[i]) {
				int y1=max(v.first,vv.first);
				int y2=min(v.second,vv.second);
				if(y2>y1) {
					int num=bt(y2)-bt(y1-1);
					ret+=1LL*num*(num-1)/2;
				}
			}
			
			FORR(a,del[i]) bt.add(a,-1);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}