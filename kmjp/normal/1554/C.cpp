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

int T,N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		vector<pair<int,int>> V;
		V.push_back({N^M,N^M});
		for(i=29;i>=0;i--) if(M&(1<<i)) {
			x=(M>>(i+1))<<(i+1);
			y=(N>>(i))<<(i);
			V.push_back({y^x,(y^x)|((1<<i)-1)});
		}
		sort(ALL(V));
		V.push_back({1<<30,1<<30});
		int pre=-1;
		FORR2(a,b,V) {
			if(pre+1==a) {
				pre=b;
			}
			else {
				break;
			}
		}
		
		cout<<pre+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}