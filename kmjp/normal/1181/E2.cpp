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

int N;
int X1[101010],X2[101010],Y1[101010],Y2[101010];

int dfs(set<pair<int,int>>& L, set<pair<int,int>>& R,set<pair<int,int>>& U,set<pair<int,int>>& D) {
	if(L.size()<=1) return 1;
	auto Lit=L.begin();
	auto Rit=R.begin();
	auto Dit=D.begin();
	auto Uit=U.begin();
	int Llim=X2[Lit->second];
	int Rlim=X1[Rit->second];
	int Dlim=Y2[Dit->second];
	int Ulim=Y1[Uit->second];
	set<pair<int,int>> L2,R2,U2,D2;
	
	while(1) {
		Lit++;
		Rit++;
		Dit++;
		Uit++;
		if(Lit==L.end()) break;
		
		if(Lit->first>=Llim) {
			auto p=*Lit;
			while(*L.begin()!=p) {
				int x=L.begin()->second;
				L2.insert({X1[x],x});
				R2.insert({-X2[x],x});
				D2.insert({Y1[x],x});
				U2.insert({-Y2[x],x});
				L.erase({X1[x],x});
				R.erase({-X2[x],x});
				D.erase({Y1[x],x});
				U.erase({-Y2[x],x});
			}
			return dfs(L,R,U,D)&&dfs(L2,R2,U2,D2);
		}
		if(Dit->first>=Dlim) {
			auto p=*Dit;
			while(*D.begin()!=p) {
				int x=D.begin()->second;
				L2.insert({X1[x],x});
				R2.insert({-X2[x],x});
				D2.insert({Y1[x],x});
				U2.insert({-Y2[x],x});
				L.erase({X1[x],x});
				R.erase({-X2[x],x});
				D.erase({Y1[x],x});
				U.erase({-Y2[x],x});
			}
			return dfs(L,R,U,D)&&dfs(L2,R2,U2,D2);
		}
		if(-Rit->first<=Rlim) {
			auto p=*Rit;
			while(*R.begin()!=p) {
				int x=R.begin()->second;
				L2.insert({X1[x],x});
				R2.insert({-X2[x],x});
				D2.insert({Y1[x],x});
				U2.insert({-Y2[x],x});
				L.erase({X1[x],x});
				R.erase({-X2[x],x});
				D.erase({Y1[x],x});
				U.erase({-Y2[x],x});
			}
			return dfs(L,R,U,D)&&dfs(L2,R2,U2,D2);
		}
		if(-Uit->first<=Ulim) {
			auto p=*Uit;
			while(*U.begin()!=p) {
				int x=U.begin()->second;
				L2.insert({X1[x],x});
				R2.insert({-X2[x],x});
				D2.insert({Y1[x],x});
				U2.insert({-Y2[x],x});
				L.erase({X1[x],x});
				R.erase({-X2[x],x});
				D.erase({Y1[x],x});
				U.erase({-Y2[x],x});
			}
			return dfs(L,R,U,D)&&dfs(L2,R2,U2,D2);
		}
		Llim=max(Llim,X2[Lit->second]);
		Rlim=min(Rlim,X1[Rit->second]);
		Dlim=max(Dlim,Y2[Dit->second]);
		Ulim=min(Ulim,Y1[Uit->second]);
	}
	
	return 0;
	
}

int dfs(vector<int>& A) {
	if(A.size()<=1) return 1;
	
	int i,R;
	vector<pair<int,int>> C;
	//X
	FORR(a,A) C.push_back({X1[a],X2[a]});
	sort(ALL(C));
	R=C[0].second;
	
	for(i=1;i<C.size();i++) {
		if(C[i].first>=R) {
			vector<int> S,T;
			
			FORR(a,A) {
				if(X2[a]<=C[i].first) S.push_back(a);
				else T.push_back(a);
			}
			return dfs(S)&dfs(T);
		}
		else {
			R=max(R,C[i].second);
		}
	}
	C.clear();
	// Y
	FORR(a,A) C.push_back({Y1[a],Y2[a]});
	sort(ALL(C));
	R=C[0].second;
	for(i=1;i<C.size();i++) {
		if(C[i].first>=R) {
			vector<int> S,T;
			
			FORR(a,A) {
				if(Y2[a]<=C[i].first) S.push_back(a);
				else T.push_back(a);
			}
			return dfs(S)&dfs(T);
		}
		else {
			R=max(R,C[i].second);
		}
	}
	
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<pair<int,int>> L,R,U,D;
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		L.insert({X1[i],i});
		R.insert({-X2[i],i});
		D.insert({Y1[i],i});
		U.insert({-Y2[i],i});
	}
	
	if(dfs(L,R,U,D)) _P("YES\n");
	else _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}