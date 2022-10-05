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
int A[201010];
int L,R;
const int D=500;
vector<int> V[500];

void erase(int id,int v) {
	int b=id/D;
	int i;
	FOR(i,V[b].size()) if(V[b][i]==v) {
		V[b].erase(V[b].begin()+i);
		return;
	}
}

void add(int id,int v) {
	int b=id/D;
	int i;
	FOR(i,V[b].size()) if(v<V[b][i]) {
		V[b].insert(V[b].begin()+i,v);
		return;
	}
	V[b].push_back(v);
}

int getmore(int id,int v) {
	int i,j;
	int ret=0;
	FOR(i,500) {
		if(id<(i+1)*D) {
			for(j=i*D;j<id;j++) if(A[j]>v && A[j]!=1<<20) ret++;
			break;
		}
		else {
			ret += V[i].end()-lower_bound(ALL(V[i]),v);
		}
	}
	return ret;
}
int getless(int id,int v) {
	int i,j;
	int ret=0;
	FOR(i,500) {
		if(id<(i+1)*D) {
			for(j=i*D;j<id;j++) if(A[j]<v) ret++;
			break;
		}
		else {
			ret += lower_bound(ALL(V[i]),v)-V[i].begin();
		}
	}
	return ret;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		A[i]=i+1;
		add(i,A[i]);
	}
	
	ll ret=0;
	
	while(Q--) {
		cin>>L>>R;
		L--,R--;
		if(L==R) {
			cout<<ret<<endl;
			continue;
		}
		if(L>R) swap(L,R);
		
		if(A[L]<A[R]) ret--;
		else ret++;
		
		ret-=getmore(R,A[R]);
		ret-=A[R]-1-getless(R,A[R]);
		ret-=getmore(L,A[L]);
		ret-=A[L]-1-getless(L,A[L]);
		erase(R,A[R]);
		erase(L,A[L]);
		
		swap(A[L],A[R]);
		add(R,A[R]);
		add(L,A[L]);
		ret+=getmore(R,A[R]);
		ret+=A[R]-1-getless(R,A[R]);
		ret+=getmore(L,A[L]);
		ret+=A[L]-1-getless(L,A[L]);
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}