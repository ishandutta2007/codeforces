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
ll N,A,B,C;
string S;

ll go(int corner,int edge,int num1,vector<int> zb,int turn) {
	multiset<int> MB;
	int SB=0;
	FORR(a,zb) {
		if(a==1) SB++;
		else MB.insert(a);
	}
	
	ll cur=0,ma=0;
	
	while(1) {
		if(turn==0) {
			if(num1) {
				cur+=B;
				num1--;
			}
			else {
				break;
			}
		}
		else {
			if(num1==0) {
				if(corner||MB.size()) {
					ma=max(ma,cur+A);
				}
				if(SB) {
					//0
					SB--;
					cur-=C;
					num1++;
				}
				else {
					break;
				}
			}
			else {
				if(MB.size()) {
					int x=*MB.begin();
					MB.erase(MB.begin());
					cur+=A;
					x--;
					if(x==1) {
						SB++;
					}
					else {
						MB.insert(x);
					}
				}
				else if(corner) {
					corner--;
					cur+=A;
				}
				else if(SB) {
					SB--;
					cur-=C;
					num1++;
				}
				else if(edge) {
					edge--;
					cur-=C;
				}
				else {
					break;
				}
			}
		
		}
		ma=max(ma,cur);
		turn^=1;
	}
	
	return ma;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>C>>S;
		
		if(N==1) {
			cout<<0<<endl;
			continue;
		}
		
		vector<pair<int,int>> V={{0,0}};
		FORR(c,S) {
			c-='0';
			if(c!=V.back().first) V.push_back({c,0});
			V.back().second++;
		}
		if(V.back().first==1) V.push_back({0,0});
		
		if(V.size()==1) {
			cout<<A<<endl;
			continue;
		}
		
		int edge=(V[0].second>0)+(V.back().second>0);
		int corner=max(0,V[0].second-1)+max(0,V.back().second-1);
		int num1=0;
		vector<int> zb;
		for(i=1;i<V.size()-1;i++) {
			if(V[i].first==1) {
				num1+=V[i].second-1;
			}
			else {
				zb.push_back(V[i].second);
			}
		}
		cout<<max(go(corner,edge,num1,zb,0),go(corner,edge,num1,zb,1))<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}