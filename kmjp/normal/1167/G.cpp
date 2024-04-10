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

int N,D;
ll A[202020];
int M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) cin>>A[i];
	
	cin>>M;
	FOR(i,M) {
		cin>>x;
		
		if(x==A[0] || x==A[N-1]+1) {
			_P("%.12lf\n",atan(1)*2);
			continue;
		}
		
		y=lower_bound(A,A+N,x)-A;
		
		if(A[y]==x && A[y-1]==x-1) {
			_P("%.12lf\n",atan(1)*4);
			continue;
		}
		if(A[y]==x || A[y-1]==x-1) {
			_P("%.12lf\n",atan(1)*2);
			continue;
		}
		
		ll dif=min(x-A[y-1]-1,A[y]-x);
		double ret=atan(1.0/dif);
		int L=y-1;
		int R=y;
		
		int ok=0;
		for(j=20;j>=0;j--) if(2*atan(1.0/(ok+(1<<j)))>=ret) ok+=1<<j;
		
		while(L>=0 && R<N) {
			int dl=x-(A[L]+1);
			int dr=A[R]-x;
			
			if(max(dl,dr)>ok) break;
			
			if(abs(dl-dr)<=1) {
				ret=2*atan(1.0/max(dl,dr));
				break;
			}
			if(dl<dr) L--;
			else R++;
		}
		
		_P("%.12lf\n",ret);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}