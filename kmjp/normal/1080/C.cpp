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


int T;
int H,W;
vector<int> Xs,Ys;
int X[4],Y[4];
int PX[4],PY[4];
int mp[10][10];

pair<ll,ll> hoge(ll x1,ll y1,ll x2,ll y2,int type) {
	ll num=(x2-x1)*(y2-y1);
	
	if(type==1) return {num,0};
	if(type==2) return {0,num};
	
	if((x1+y1)%2) return {num/2,num-num/2};
	else return {num-num/2,num/2};
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		Xs.clear();
		Ys.clear();
		Xs.push_back(0);
		Ys.push_back(0);
		Xs.push_back(W);
		Ys.push_back(H);
		ZERO(mp);
		FOR(i,4) cin>>X[i]>>Y[i];
		X[0]--,Y[0]--;
		X[2]--,Y[2]--;
		FOR(i,4) Xs.push_back(X[i]),Ys.push_back(Y[i]);
		sort(ALL(Xs));
		sort(ALL(Ys));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		Ys.erase(unique(ALL(Ys)),Ys.end());
		FOR(i,4) {
			PX[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
			PY[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		}
		for(y=PY[0];y<PY[1];y++) for(x=PX[0];x<PX[1];x++) mp[x][y]=1;
		for(y=PY[2];y<PY[3];y++) for(x=PX[2];x<PX[3];x++) mp[x][y]=2;
		
		pair<ll,ll> p={0,0};
		FOR(x,Xs.size()-1) FOR(y,Ys.size()-1) {
			auto pp=hoge(Xs[x],Ys[y],Xs[x+1],Ys[y+1],mp[x][y]);
			p.first+=pp.first;
			p.second+=pp.second;
		}
		cout<<p.first<<" "<<p.second<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}