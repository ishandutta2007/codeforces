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

int N,Q;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> R,C;
int NR[202020],NC[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			NR[x]++;
			if(NR[x]==1) R.add(x,1);
			NC[y]++;
			if(NC[y]==1) C.add(y,1);
		}
		else if(i==2) {
			NR[x]--;
			if(NR[x]==0) R.add(x,-1);
			NC[y]--;
			if(NC[y]==0) C.add(y,-1);
		}
		else {
			int x2,y2;
			cin>>x2>>y2;
			j=R(x2)-R(x-1);
			k=C(y2)-C(y-1);
			if(j==x2-x+1||k==y2-y+1) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}