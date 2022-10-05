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

int H,W,Q;
vector<pair<int,int>> C[1010][1010];
set<int> S[5040];
int A[1010][1010];
int avail;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(j,2050) {
		x=-3;
		y=-1020+j;
		int dir=i;
		int step=0;
		while(x<W+5) {
			if(x>=0&&x<W&&y>=0&&y<H) {
				C[y][x].push_back({j,step});
			}
			else {
				S[j].insert(step);
			}
			if(dir==0) x++;
			else y++;
			step++;
			dir^=1;
		}
	}
	avail=H*W;
	ll sum=0;
	FOR(i,5000) if(S[i].size()>=2) {
		int pre=-1;
		FORR(s,S[i]) {
			if(pre>=0) {
				x=s-pre;
				sum+=1LL*(x-1)*(x-2)/2;
			}
			pre=s;
		}
	}
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		FORR2(id,step,C[y][x]) {
			if(A[y][x]==0) {
				auto it=S[id].lower_bound(step);
				int nex=*it;
				int pre=*prev(it);
				
				sum-=1LL*(nex-pre-1)*(nex-pre-2)/2;
				sum+=1LL*(step-pre-1)*(step-pre-2)/2;
				sum+=1LL*(nex-step-1)*(nex-step-2)/2;
				
				S[id].insert(step);
			}
			else {
				S[id].erase(step);
				auto it=S[id].lower_bound(step);
				int nex=*it;
				int pre=*prev(it);
				sum-=1LL*(step-pre-1)*(step-pre-2)/2;
				sum-=1LL*(nex-step-1)*(nex-step-2)/2;
				sum+=1LL*(nex-pre-1)*(nex-pre-2)/2;
			}
		}
		if(A[y][x]==0) {
			avail--;
		}
		else {
			avail++;
		}
		A[y][x]^=1;
		cout<<sum+avail<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}