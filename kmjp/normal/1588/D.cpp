#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N;
int L[10];
string S[10];
char C[256];
int nex[10][155][55];

vector<int> P[10][55];

int len[53][1024];
int from[53][1024];
vector<int> E[53][1024];
int in[53][1024];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C['#']=0;
	FOR(i,26) {
		C['a'+i]=i+1;
		C['A'+i]=i+27;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(j,53) FOR(k,1<<N) {
			len[j][k]=-10000;
			E[j][k].clear();
			in[j][k]=0;
		}
		len[0][0]=0;

		FOR(i,N) {
			cin>>S[i];
			S[i]="#"+S[i];
			L[i]=S[i].size();
			FOR(j,53) P[i][j].clear();
			FOR(j,L[i]) {
				S[i][j]=C[S[i][j]];
				P[i][S[i][j]].push_back(j);
			}
			FOR(j,53) nex[i][L[i]][j]=L[i];
			for(j=L[i]-1;j>=0;j--) {
				FOR(x,53) nex[i][j][x]=nex[i][j+1][x];
				nex[i][j][S[i][j]]=j;
			}
		}
		
		
		FOR(j,53) FOR(k,1<<N) {
			FOR(r,53) {
				int nm=0;
				FOR(i,N) {
					x=((k>>i)&1);
					if(x>=P[i][j].size()) break;
					y=nex[i][P[i][j][x]+1][r];
					if(y==L[i]) break;
					if(P[i][r][0]!=y) nm|=1<<i;
				}
				if(i!=N) continue;
				E[j][k].push_back(r*10000+nm);
				in[r][nm]++;
			}
		}
		queue<int> Q;
		FOR(j,53) FOR(k,1<<N) if(in[j][k]==0) Q.push(j*10000+k);
		int ma=0,cc=0,cmask=0;
		while(Q.size()) {
			int c=Q.front()/10000;
			int mask=Q.front()%10000;
			Q.pop();
			
			if(len[c][mask]>ma) {
				ma=len[c][mask];
				cc=c;
				cmask=mask;
			}
			
			FORR(e,E[c][mask]) {
				int tc=e/10000;
				int tm=e%10000;
				if(len[tc][tm]<len[c][mask]+1) {
					len[tc][tm]=len[c][mask]+1;
					from[tc][tm]=c*10000+mask;
				}
				in[tc][tm]--;
				if(in[tc][tm]==0) Q.push(tc*10000+tm);
			}
		}
		
		string R;
		while(ma) {
			x=from[cc][cmask]/10000;
			y=from[cc][cmask]%10000;
			if(cc>=1&&cc<=26) R+='a'+cc-1;
			if(cc>=27&&cc<=53) R+='A'+cc-27;
			cc=x;
			cmask=y;
			ma--;
		}
		reverse(ALL(R));
		cout<<R.size()<<endl;
		cout<<R<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}