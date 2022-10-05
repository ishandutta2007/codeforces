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

int N,Q;
int A[202020];
vector<int> cand3[202020];
vector<int> cand4[202020];
vector<pair<int,int>> U,D;
set<int> US,DS;
set<int> S;
int mo[202020],le[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	
	vector<pair<int,int>> V;
	FOR(i,N) {
		scanf("%d",&A[i]);
		V.push_back({A[i],i});
	}
	
	sort(ALL(V));
	
	FOR(i,2) {
		set<int> S;
		S.insert(-1);
		S.insert(N);
		FOR(x,N) {
			for(y=x;y<N&&V[y].first==V[x].first;y++) {
				int t=V[y].second;
				int R=*S.lower_bound(t);
				int L=*prev(S.lower_bound(t));
				if(L>=0 && R<N && (cand3[R].empty()||cand3[R][0]<L)) cand3[R]={L,t,R};
			}
			for(y=x;y<N&&V[y].first==V[x].first;y++) {
				S.insert(V[y].second);
			}
			x=y-1;
		}
		reverse(ALL(V));
	}
	
	U.push_back({1<<30,N});
	D.push_back({-(1<<30),N});
	US.insert(N);
	DS.insert(N);
	S.insert(N);
	vector<int> W;
	for(i=N-1;i>=0;i--) {
		while(U.back().first<A[i]) {
			if(DS.count(U.back().second)==0) S.insert(U.back().second);
			US.erase(U.back().second);
			U.pop_back();
			
		}
		while(D.back().first>A[i]) {
			if(US.count(D.back().second)==0) S.insert(D.back().second);
			DS.erase(D.back().second);
			D.pop_back();
		}
		
		if(A[i]==U.back().first) mo[i]=mo[U.back().second];
		else mo[i]=U.back().second;
		if(A[i]==D.back().first) le[i]=le[D.back().second];
		else le[i]=D.back().second;
		
		
		y=*S.lower_bound(max(mo[i],le[i]));
		U.push_back({A[i],i});
		D.push_back({A[i],i});
		/*
		FORR(u,U) cout<<u.first<<":"<<u.second<<" ";
		cout<<endl;
		FORR(u,D) cout<<u.first<<":"<<u.second<<" ";
		cout<<endl;
		FORR(s,S) cout<<s<<" ";
		cout<<endl;
		*/
		US.insert(i);
		DS.insert(i);
		if(A[i]==A[i+1]) continue;
		//cout<<"!"<<y<<endl;
		if(y<N && cand4[y].empty()) {
			x=*prev(US.lower_bound(y));
			j=*prev(DS.lower_bound(y));
			//cout<<i+1<<" "<<x+1<<" "<<j+1<<" "<<y+1<<endl;
			if(x>i && j>i && x<y && j<y) cand4[y]={i,min(x,j),max(x,j),y};
		}
	}
	
	
	vector<int> ok3={-1,-1,-1},ok4={-1,-1,-1,-1};
	FOR(i,N) {
		if(cand3[i].size()) ok3=max(ok3,cand3[i]);
		cand3[i]=ok3;
		if(cand4[i].size()) ok4=max(ok4,cand4[i]);
		cand4[i]=ok4;
	}
	
	FOR(i,Q) {
		int L,R;
		scanf("%d%d",&L,&R);
		L--;
		R--;
		/*
		if(N==199985 && Q==200000&&i!=63) continue;
		if(N==199985 && Q==200000&&i==63) {
			cout<<L<<" "<<R<<" ";
			for(j=L;j<=R;j++) cout<<A[j]<<" ";
			cout<<endl;
		}
		*/
		if(cand4[R][0]>=L) {
			cout<<4<<endl;
			cout<<cand4[R][0]+1<<" "<<cand4[R][1]+1<<" "<<cand4[R][2]+1<<" "<<cand4[R][3]+1<<endl;
		}
		else if(cand3[R][0]>=L) {
			cout<<3<<endl;
			cout<<cand3[R][0]+1<<" "<<cand3[R][1]+1<<" "<<cand3[R][2]+1<<endl;
		}
		else {
			cout<<0<<endl;
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}