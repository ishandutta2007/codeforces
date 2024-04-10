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
ll X[101010],Y[101010];
map<int,int> M;

int ok(int a,int b,int c) {
	
	
	ll B1=(Y[b]-Y[a])*(X[c]-X[a])-(X[a]+X[b])*(X[b]-X[a])*(X[c]-X[a]);
	ll B2=(Y[c]-Y[a])*(X[b]-X[a])-(X[a]+X[c])*(X[b]-X[a])*(X[c]-X[a]);
	return B1>B2;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		if(M.count(x)==0) {
			M[x]=y;
		}
		else {
			M[x]=max(M[x],y);
		}
	}
	i=0;
	N=M.size();
	FORR(m,M) {
		X[i]=m.first;
		Y[i]=m.second;
		i++;
	}
	
	deque<int> Q;
	FOR(i,N) {
		while(Q.size()>=2) {
			y=Q.back();
			Q.pop_back();
			if(ok(Q.back(),y,i)) {
				Q.push_back(y);
				break;
			}
		}
		Q.push_back(i);
	}
	
	cout<<Q.size()-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}