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

int X,Y,Z,N,M,K;
int L[3],R[3];
int OK[101010][3],NG[101010][3],Q[101010][3];

int ret[101010];
vector<pair<int,int>> query[8];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d%d%d%d",&X,&Y,&Z,&N,&M,&K);
	R[0]=R[1]=R[2]=1;
	L[0]=X;
	L[1]=Y;
	L[2]=Z;
	FOR(i,N) {
		scanf("%d%d%d",&OK[i][0],&OK[i][1],&OK[i][2]);
		FOR(j,3) L[j]=min(L[j],OK[i][j]),R[j]=max(R[j],OK[i][j]);
	}
	FOR(i,M) {
		scanf("%d%d%d",&NG[i][0],&NG[i][1],&NG[i][2]);
		int ok=0;
		FOR(j,3) {
			if(NG[i][j]<L[j] || R[j]<NG[i][j]) ok=1;
			if(NG[i][j]>R[j]) NG[i][j]-=R[j]-L[j];
			else if(NG[i][j]>=L[j]) NG[i][j]=L[j];
		}
		if(ok==0)  return _P("INCORRECT\n");
		
		FOR(j,8) {
			int ok=1;
			FOR(x,3) {
				y=(j>>x)&1;
				if(y==0 && NG[i][x]>L[x]) ok=0;
				if(y==1 && NG[i][x]<L[x]) ok=0;
			}
			if(ok) {
				if(j&4) query[j].push_back({NG[i][2],i});
				else query[j].push_back({Z+1-NG[i][2],i});
			}
		}
		
	}
	FOR(i,K) {
		scanf("%d%d%d",&Q[i][0],&Q[i][1],&Q[i][2]);
		ret[i]=1;
		FOR(j,3) {
			ret[i]&=(L[j]<=Q[i][j]&&Q[i][j]<=R[j]);
			if(Q[i][j]>R[j]) Q[i][j]-=R[j]-L[j];
			else if(Q[i][j]>=L[j]) Q[i][j]=L[j];
		}
		if(ret[i]==0) {
			FOR(j,8) {
				int ok=1;
				FOR(x,3) {
					y=(j>>x)&1;
					if(y==0 && Q[i][x]>L[x]) ok=0;
					if(y==1 && Q[i][x]<L[x]) ok=0;
				}
				if(ok) {
					if(j&4) query[j].push_back({Q[i][2],100000+i});
					else query[j].push_back({Z+1-Q[i][2],100000+i});
				}
			}
		}
	}
	
	FOR(i,8) {
		map<ll,ll> mp;
		mp[0]=1000000;
		mp[1000000]=0;
		sort(ALL(query[i]));
		FORR(z,query[i]) {
			j=z.second;
			if(j<100000) {
				x=NG[j][0];
				y=NG[j][1];
				if((i&1)==0) x=X+1-x;
				if((i&2)==0) y=Y+1-y;
				auto it=mp.lower_bound(x+1);
				it--;
				if(it->second>=y) {
					mp[x]=y;
					while(1) {
						it=mp.lower_bound(x+1);
						if(it->second<y) break;
						mp.erase(it);
					}
				}
			}
			else {
				j-=100000;
				x=Q[j][0];
				y=Q[j][1];
				if((i&1)==0) x=X+1-x;
				if((i&2)==0) y=Y+1-y;
				auto it=mp.lower_bound(x+1);
				it--;
				if(it->second<=y) ret[j]=2;
			}
		}
		
	}
	
	_P("CORRECT\n");
	FOR(i,K) {
		if(ret[i]==1) _P("OPEN\n");
		if(ret[i]==2) _P("CLOSED\n");
		if(ret[i]==0) _P("UNKNOWN\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}