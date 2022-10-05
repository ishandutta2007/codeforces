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
vector<int> E[1010];
int inval[1010];
int D[1010][1010];

int ask(int x,int y) {
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}
void ans(int v) {
	cout<<"! "<<v<<endl;
	exit(0);
	return;
}

int istar(int cur,int pre,int tar) {
	if(cur==tar) return 1;
	int ret=0;
	FORR(e,E[cur]) if(e!=pre) ret|=istar(e,cur,tar);
	return ret;
}
void godel(int cur,int pre) {
	inval[cur]=1;
	FORR(e,E[cur]) if(e!=pre) godel(e,cur);
}

void del(int root,int tar) {
	FORR(e,E[root]) if(istar(e,root,tar)) {
		godel(e,root);
	}
}

void dist(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	FORR(e,E[cur]) if(e!=pre) dist(e,cur,id,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(i=1;i<=N;i++) dist(i,i,i,0);
	
	while(1) {
		vector<int> V;
		for(j=1;j<=N;j++) if(inval[j]==0) V.push_back(j);
		if(V.size()==1) {
			ans(V[0]);
		}
		else {
			x=y=-1;
			FORR(a,V) FORR(b,V) {
				if(D[a][b]>=3) {
					x=a;
					y=b;
					goto out;
				}
			}
			FORR(a,V) FORR(b,V) {
				if(D[a][b]>=2) {
					x=a;
					y=b;
					goto out;
				}
			}
			x=V[0];
			y=V[1];
			out:
			//cout<<x<<y<<D[x][y]<<endl;
			r=ask(x,y);
			if(r!=x) del(r,x);
			if(r!=y) del(r,y);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}