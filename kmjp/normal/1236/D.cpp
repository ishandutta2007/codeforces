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

int H,W,K;
set<int> Rs[101010];
set<int> Cs[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K) {
		cin>>y>>x;
		y--,x--;
		Rs[y].insert(x);
		Cs[x].insert(y);
	}
	
	int L=0,R=W-1,U=0,D=H-1;
	ll walk=1;
	int turn=0;
	while(L<R || U<D) {
		if(turn==0) {
			auto it=Rs[U].lower_bound(L);
			int NR=R;
			if(it!=Rs[U].end()) NR=min(NR,*it-1);
			if(L==NR && (L||U)) break;
			R=NR;
			walk += R-L;
			if(L||U) L++;
		}
		else if(turn==1) {
			auto it=Cs[R].lower_bound(U);
			int ND=D;
			if(it!=Cs[R].end()) ND=min(ND,*it-1);
			if(U==ND) break;
			D=ND;
			walk += D-U;
			U++;
		}
		else if(turn==2) {
			auto it=Rs[D].lower_bound(R);
			int NL=L;
			if(it!=Rs[D].begin()) {
				it--;
				NL=max(NL,*it+1);
			}
			if(R==NL) break;
			L=NL;
			walk += R-L;
			R--;
		}
		else if(turn==3) {
			auto it=Cs[L].lower_bound(D);
			int NU=U;
			if(it!=Cs[L].begin()) {
				it--;
				NU=max(NU,*it+1);
			}
			if(D==NU) break;
			U=NU;
			walk += D-U;
			D--;
		}
		turn=(turn+1)%4;
	}
	
	if(walk+K==1LL*H*W) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}