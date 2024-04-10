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


int N,M,K;
int L[2020],R[2020];
int C[2020][4020];
vector<int> pos[2020][2020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,15> bt;


int num(int a,int b,int x,int y) {
	a=max(a,x);
	b=min(b,y);
	return max(0,b-a);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]--;
		for(x=0;x+K<=2*N;x++) {
			C[i][x]=num(x,x+K,L[i],R[i]);
			//cout<<C[i][x];
			pos[i][C[i][x]].push_back(x);
			if(x==0) bt.add(x,C[i][x]);
			else bt.add(x,max(C[i][x],C[i][0])-max(C[i][x-1],C[i][0]));
		}
		
	}
	
	int ret=0;
	for(x=0;x+K<=N;x++) {
		if(x) {
			FOR(i,M) {
				if(C[i][x]>C[i][x-1]) {
					y=pos[i][C[i][x]].back()+1;
					bt.add(y,1);
				}
				if(C[i][x]<C[i][x-1]) {
					bt.add(x,-1);
				}
			}
			
		}
		int ma=0;
		//for(y=x;y+K<=N;y++) cout<<y<<":"<<bt(y)<<" ";
		for(y=x;y+K<=N;y++) ma=max(ma,bt(y));
		//cout<<x<<" "<<ma<<endl;
		ret=max(ret,ma);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}