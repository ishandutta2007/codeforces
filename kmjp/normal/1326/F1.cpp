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
string S[18];
ll ret[1<<17];
int rev[1<<18];

unordered_map<int,int> cnt[1<<14][14];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	
	FOR(i,N) cnt[1<<i][i][0]=1;
	for(int mask=0;mask<1<<N;mask++) {
		int nb=__builtin_popcount(mask);
		if(nb>=7) continue;
		FOR(i,N) {
			FORR(m,cnt[mask][i]) {
				FOR(j,N) if((mask&(1<<j))==0) {
					int nm=m.first*2;
					if(S[i][j]=='1') nm |= 1;
					cnt[mask|(1<<j)][j][nm]+=m.second;
				}
			}
		}
	}
	
	int H=N/2;
	FOR(i,1<<(H-1)) {
		x=0;
		FOR(j,H-1) if(i&(1<<j)) x|=1<<(H-2-j);
		rev[x]=i;
	}
	for(int mask=0;mask<1<<N;mask++) {
		int nb=__builtin_popcount(mask);
		if(nb!=H) continue;
		int smask=((1<<N)-1)^mask;
		FOR(i,N) if(mask&(1<<i)) {
			FOR(j,N) if(smask&(1<<j)) {
				FORR(m1,cnt[mask][i]) FORR(m2,cnt[smask][j]) {
					int nmask=(m2.first<<H) | ((S[i][j]=='1')<<(H-1)) | rev[m1.first];
					//cout<<nmask<<" "<<mask<<" "<<i<<" "<<smask<<" "<<j<<" "<<m1.first<<" "<<m2.first<<" "<<m1.second<<"*"<<m2.second<<endl;
					ret[nmask]+=1LL*m1.second*m2.second;
				}
			}
		}
	}
	
	
	
	FOR(i,1<<(N-1)) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}