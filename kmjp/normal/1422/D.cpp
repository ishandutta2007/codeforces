#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int SY,SX,FY,FX;
int X[101010],Y[101010],Xid[101010],Yid[101010];
pair<int,int> Xs[101010],Ys[101010];

ll D[101010],D2[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>N;
	cin>>SX>>SY>>FX>>FY;
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs[i]={X[i],i};
		Ys[i]={Y[i],i};
		D[i]=min(abs(SX-X[i]),abs(SY-Y[i]));
		D2[i]=abs(FX-X[i])+abs(FY-Y[i]);
		Q.push({-D[i],i});
	}
	sort(Xs,Xs+N);
	sort(Ys,Ys+N);
	FOR(i,N) Xid[Xs[i].second]=Yid[Ys[i].second]=i;
	
	ll mi=abs(SX-FX)+abs(SY-FY);
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		mi=min(mi,D[cur]+D2[cur]);
		x=Xid[cur];
		y=Yid[cur];
		
		if(x>0 && D[Xs[x-1].second] > co+Xs[x].first-Xs[x-1].first) {
			D[Xs[x-1].second]=co+Xs[x].first-Xs[x-1].first;
			Q.push({-D[Xs[x-1].second],Xs[x-1].second});
		}
		if(x+1<N && D[Xs[x+1].second] > co+Xs[x+1].first-Xs[x].first) {
			D[Xs[x+1].second]=co+Xs[x+1].first-Xs[x].first;
			Q.push({-D[Xs[x+1].second],Xs[x+1].second});
		}
		if(y>0 && D[Ys[y-1].second] > co+Ys[y].first-Ys[y-1].first) {
			D[Ys[y-1].second]=co+Ys[y].first-Ys[y-1].first;
			Q.push({-D[Ys[y-1].second],Ys[y-1].second});
		}
		if(y+1<N && D[Ys[y+1].second] > co+Ys[y+1].first-Ys[y].first) {
			D[Ys[y+1].second]=co+Ys[y+1].first-Ys[y].first;
			Q.push({-D[Ys[y+1].second],Ys[y+1].second});
		}
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}