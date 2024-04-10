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

int H,W;
int mask[251][251];
vector<int> V[256];
string S[256];

int hoge(int A,int B) {
	if(A>B) return 0;
	
	int L=B-A+1,i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && V[A+(i-j)/2]==V[A+(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k; k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	int ret=0;
	FOR(i,2*L-1) {
		if(i%2) ret+=rad[i]/2;
		else ret+=(rad[i]+1)/2;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			mask[y][x+1]=mask[y][x] ^ (1<<(S[y][x]-'a'));
		}
	}
	
	ll ret=0;
	FOR(x,W) {
		FOR(y,H) V[y]=vector<int>(26,0);
		for(l=1;x+l<=W;l++) {
			int pre=0;
			FOR(y,H) {
				ll r=mask[y][x+l]^mask[y][x];
				V[y][S[y][x+l-1]-'a']++;
				if(__builtin_popcount(r)>1) {
					ret+=hoge(pre,y-1);
					pre=y+1;
				}
			}
			ret+=hoge(pre,H-1);
			
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}