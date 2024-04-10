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

int A[515][515];
int B[515][515];
int C[515][515];
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=2;i<=1505;i++) {
		if(N-->0) cout<<i<<" "<<250<<endl;
		if(i%2 && N-->0) cout<<i<<" "<<253<<endl;
	}
	return;
	
	
	int num=0;
	for(N=1;N<=100;N++) {
		ZERO(A);
		
		x=N;
		for(i=2;i<=505;i++) {
			if(x) A[i][250]=1, x--;
			if(x && i%2) A[i][253]=1, x--;
			
		}
		
		/*
		if(N>10) {
			i=N/4;
			for(j=0;j<N/4;j++) {
				A[250-j][250+i-j]=1;
				A[250+j+1][250+i-j]=1;
				C[250-j][250+i-j]=4;
				C[250+j+1][250+i-j]=4;
				
			}
			i=N/4-4;
			for(j=0;j<N/4-1;j++) {
				A[250-j][250+i-j]=1;
				A[250+j+1][250+i-j]=1;
				C[250-j][250+i-j]=4;
				C[250+j+1][250+i-j]=4;
			}
		}
		*/
		num=0;
		FOR(y,500) FOR(x,500) num+=A[y][x];
		
		int up=1;
		int tot=num;
		while(up) {
			up=0;
			for(y=2;y<=510;y++) for(x=2;x<=510;x++) if(A[y][x]==0) {
				int num=0;
				int dx[8]={-2,-1,-1,-2,2,1,1,2};
				int dy[8]={-1,-2,2,1,-1,-2,2,1};
				FOR(j,8) num+=A[y+dy[j]][x+dx[j]];
				if(num>=4) {
					A[y][x]=1, up=1,tot++;
					FOR(j,8) if(A[y+dy[j]][x+dx[j]]) B[y+dy[j]][x+dx[j]]=2;
				}
			}
		}
		cout<<N<<" "<<tot<<" "<<N*N/10<<endl;
		for(y=2;y<=100;y++) {
			for(x=200;x<=300;x++) cout<<A[y][x]+B[y][x]+C[y][x];
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