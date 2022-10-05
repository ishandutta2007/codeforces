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

int T;
int H,W;
vector<int> A[555555];
vector<int> Lmi[555555],Lma[555555],Rmi[555555],Rma[555555];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			A[y].resize(W);
			Lmi[y].resize(W);
			Lma[y].resize(W);
			Rmi[y].resize(W);
			Rma[y].resize(W);
			FOR(x,W) {
				cin>>A[y][x];
				Lmi[y][x]=Lma[y][x]=Rmi[y][x]=Rma[y][x]=A[y][x];
				if(x) Lmi[y][x]=min(Lmi[y][x-1],Lmi[y][x]);
				if(x) Lma[y][x]=max(Lma[y][x-1],Lma[y][x]);
			}
			for(x=W-2;x>=0;x--) {
				Rmi[y][x]=min(Rmi[y][x],Rmi[y][x+1]);
				Rma[y][x]=max(Rma[y][x],Rma[y][x+1]);
			}
		}
		string R;
		int retx;
		FOR(x,W-1) if(R.empty()) {
			vector<pair<int,int>> LRmi;
			multiset<int> RR,LRma;
			int LBma=0,RBmi=1<<30;
			FOR(y,H) {
				LRmi.push_back({Lmi[y][x],y});
				LRma.insert(Lma[y][x]);
				RR.insert(Rma[y][x+1]);
			}
			sort(ALL(LRmi));
			R=string(H,'R');
			FOR(i,H-1) {
				auto y=LRmi[i].second;
				R[y]='B';
				LRma.erase(LRma.find(Lma[y][x]));
				LBma=max(LBma,Lma[y][x]);
				RR.erase(RR.find(Rma[y][x+1]));
				RBmi=min(RBmi,Rmi[y][x+1]);
				if(LBma>=LRmi[i+1].first) continue;
				if(*RR.rbegin()>=RBmi) continue;
				
				retx=x+1;
				break;
			}
			if(i==H-1) R="";
		}
		if(R.size()) {
			cout<<"YES"<<endl;
			cout<<R<<" "<<retx<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}