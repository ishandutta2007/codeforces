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

bitset<2020> R[2020],pref[2020];
int H,W,Q;

set<pair<int,int>> cand;
bitset<2020> ans;
int P[2020];

void check(int l,int r) {
	if(l<0 || r>=H) return;
	if((R[l]|R[r])!=R[r]) {
		P[l]=r;
		ans.set(l);
	}
}

void del(int y) {
	P[y]=-1;
	ans.reset(y);
	int c=R[y].count();
	auto it=cand.find({c,y});
	auto lef=it,rig=it;
	lef--;rig++;
	int le=lef->second;
	int ri=rig->second;
	cand.erase(it);
	if(le>=0 && P[le]>=0) P[le]=-1, ans.reset(le);
	check(le,ri);
}

void ins(int y) {
	int c=R[y].count();
	cand.insert({c,y});
	auto it=cand.find({c,y});
	auto lef=it,rig=it;
	lef--;rig++;
	int le=lef->second;
	int ri=rig->second;
	if(le>=0 && P[le]>=0) P[le]=-1, ans.reset(le);
	check(le,y);
	check(y,ri);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(P);
	scanf("%d%d%d",&H,&W,&Q);
	FOR(y,2010) FOR(x,y) pref[y].set(x);
	
	cand.insert({-1,-1});
	cand.insert({W+1,H});
	FOR(y,H) cand.insert({0,y});
	
	while(Q--) {
		int A,l,r;
		scanf("%d%d%d",&A,&l,&r);
		A--;
		del(A);
		R[A]^=pref[r];
		R[A]^=pref[l-1];
		ins(A);
		
		if(ans.count()==0) {
			_P("-1\n");
		}
		else {
			int y1=ans._Find_first();
			int y2=P[y1];
			if(y1>y2) swap(y1,y2);
			int x1=(R[y1]&~R[y2])._Find_first();
			int x2=(R[y2]&~R[y1])._Find_first();
			if(x1>x2) swap(x1,x2);
			_P("%d %d %d %d\n",y1+1,x1+1,y2+1,x2+1);
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}