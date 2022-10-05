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

struct node {
	int M;
	int id;
	int mi[10],ma[10];
};

int N,K;
struct node S[50505];

struct node* winner;
set<pair<int,int>> cand[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	FOR(i,N) {
		S[i].M=1;
		S[i].id=i;
		FOR(j,K) {
			scanf("%d",&x);
			S[i].mi[j]=S[i].ma[j]=x;
		}
		
		if(i==0) {
			winner=&S[0];
		}
		else {
			int allwin=1,alllose=1;
			FOR(j,K) {
				if(S[i].mi[j]<winner->ma[j]) allwin=0;
				if(S[i].ma[j]>winner->mi[j]) alllose=0;
			}
			if(allwin==1) {
				FOR(j,K) cand[j].insert({winner->ma[j],winner->id});
				winner=&S[i];
			}
			else if(alllose==1) {
				FOR(j,K) cand[j].insert({S[i].ma[j],S[i].id});
			}
			else {
				winner->M++;
				FOR(j,K) {
					winner->mi[j]=min(winner->mi[j],S[i].mi[j]);
					winner->ma[j]=max(winner->ma[j],S[i].ma[j]);
				}
				int up=1;
				while(up) {
					up=0;
					FOR(j,K) if(cand[j].size() && cand[j].rbegin()->first > winner->mi[j]) {
						x=cand[j].rbegin()->second;
						break;
					}
					
					if(j<K) {
						up=1;
						winner->M+=S[x].M;
						FOR(j,K) {
							cand[j].erase({S[x].ma[j],x});
							winner->mi[j]=min(winner->mi[j],S[x].mi[j]);
							winner->ma[j]=max(winner->ma[j],S[x].ma[j]);
						}
					}
				}
				
			}
		}
		
		_P("%d\n",winner->M);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}