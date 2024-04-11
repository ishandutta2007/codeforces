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

int H,W,K;
string S[1010];

/*
int D[1010][1010][26];
ll SD[1010][1010][26];
*/
int num[1010][1010][27];

int R0[303030];
int C0[303030];
int R1[303030];
int C1[303030];
char C[303030];

ll difsum[1010][1010];
ll difsum2[1010][1010];
int col[1010][1010][26];
ll colsum[1010][1010][26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			S[y][x]-='a';
			/*
			FOR(i,26) {
				D[y][x][i] = abs(i-S[y][x]);
				SD[y+1][x+1][i] = SD[y+1][x][i] + SD[y][x+1][i] - SD[y][x][i] + D[y][x][i];
			}
			*/
		}
	}
	num[0][0][26]=K;
	num[H][W][26]=K;
	num[H][0][26]=-K;
	num[0][W][26]=-K;
	
	FOR(i,K) {
		cin>>R0[i]>>C0[i]>>R1[i]>>C1[i]>>C[i];
		R0[i]--;
		C0[i]--;
		R1[i]--;
		C1[i]--;
		C[i]-='a';
		num[R0[i]][C0[i]][C[i]]++;
		num[R0[i]][C1[i]+1][C[i]]--;
		num[R1[i]+1][C0[i]][C[i]]--;
		num[R1[i]+1][C1[i]+1][C[i]]++;
		
		num[R0[i]][C0[i]][26]--;
		num[R0[i]][C1[i]+1][26]++;
		num[R1[i]+1][C0[i]][26]++;
		num[R1[i]+1][C1[i]+1][26]--;
	}
	FOR(y,H) FOR(x,W) {
		FOR(i,27) {
			if(y) num[y][x][i] += num[y-1][x][i];
			if(x) num[y][x][i] += num[y][x-1][i];
			if(y&&x) num[y][x][i] -= num[y-1][x-1][i];
		}
	}
	FOR(y,H) FOR(x,W) num[y][x][S[y][x]] += num[y][x][26];
	FOR(y,H) FOR(x,W) {
		ll nu=0,sum=0;
		for(i=25;i>=0;i--) {
			col[y][x][i] += sum;
			nu += num[y][x][i];
			sum += nu;
		}
		nu=0,sum=0;
		FOR(i,26) {
			col[y][x][i] += sum;
			colsum[y+1][x+1][i]=colsum[y+1][x][i]+colsum[y][x+1][i]-colsum[y][x][i]+col[y][x][i];
			nu += num[y][x][i];
			sum += nu;
		}
	}
	FOR(y,H) FOR(x,W) {
		FOR(i,26) difsum[y][x]+=1LL*abs(S[y][x]-i)*num[y][x][i];
		difsum2[y+1][x+1]=difsum2[y+1][x]+difsum2[y][x+1]-difsum2[y][x]+difsum[y][x];
	}
	
	ll mi=1LL<<60;
	FOR(i,K) {
		ll v = difsum2[H][W];
		v -= difsum2[R1[i]+1][C1[i]+1]-difsum2[R0[i]][C1[i]+1]-difsum2[R1[i]+1][C0[i]]+difsum2[R0[i]][C0[i]];
		v += colsum[R1[i]+1][C1[i]+1][C[i]]-colsum[R0[i]][C1[i]+1][C[i]]-colsum[R1[i]+1][C0[i]][C[i]]+colsum[R0[i]][C0[i]][C[i]];
		mi=min(mi,v);
	}
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}