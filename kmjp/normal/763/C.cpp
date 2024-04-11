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

ll N,M;
ll A[101010];
bitset<1<<20> BS[1024];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	FOR(i,N) cin>>A[i], BS[A[i]>>20][A[i]&((1<<20)-1)]=1;
	
	if(N==1) {
		cout<<A[0]<<" "<<0<<endl;
		return;
	}
	if(N==M-1) {
		FOR(i,M) if(BS[0][i]==0) {
			cout<<(i+1)%M<<" "<<1<<endl;
			return;
		}
	}
	if(N==M) {
		cout<<0<<" "<<1<<endl;
		return;
	}
	sort(A,A+N);
	
	if(2*N<M) {
		for(i=1;i<N;i++) {
			int d=A[i]-A[0];
			
			ll L,R,cur=A[0];
			for(R=0;R<N-1;R++) {
				cur+=d;
				if(cur>=M) cur-=M;
				if(BS[cur>>20][cur&((1<<20)-1)]==0) break;
			}
			cur=A[0];
			for(L=0;L+R<N-1;L++) {
				cur+=M-d;
				if(cur>=M) cur-=M;
				if(BS[cur>>20][cur&((1<<20)-1)]==0) break;
			}
			if(L+R>=N-1) {
				ll P=((A[0]-L*d)%M+M)%M;
				cout<<P<<" "<<d<<endl;
				return;
			}
		}
	}
	else {
		int le=M-N;
		FOR(i,M) BS[0][i]=1;
		FOR(i,N) BS[0][A[i]]=0;
		int first=-1;
		FOR(i,M) if(BS[0][i]==1) {
			if(first==-1) {
				first=i;
			}
			else {
				ll d=i-first;
				
				ll L,R,cur=first;
				for(R=0;R<le-1;R++) {
					cur+=d;
					if(cur>=M) cur-=M;
					if(BS[0][cur]==0) break;
				}
				cur=first;
				for(L=0;L+R<le-1;L++) {
					cur+=M-d;
					if(cur>=M) cur-=M;
					if(BS[0][cur]==0) break;
				}
				if(L+R>=le-1) {
					ll P=((first-L*d)%M+M)%M;
					cout<<(P+le*d)%M<<" "<<d<<endl;
					return;
				}
			}
		}
		
		
		
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}