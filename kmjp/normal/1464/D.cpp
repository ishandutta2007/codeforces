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
int P[1010100];
int did[1010101];
const ll mo=1000000007;

int hoge(vector<int> V) {
	int ret=0;
	int C[3]={};
	int can4=0;
	FORR(v,V) {
		ret+=(v-1)/3;
		C[v%3]++;
		if(v%3==1&&v>=4) can4=1;
	}
	
	if(N%3==2) {
		if(C[2]) C[2]--;
		else ret++, C[1]-=2;
	}
	else if(N%3==1) {
		//2*2
		if(C[2]>=C[1]+2) { // 2 2
			C[2]-=2;
		}
		else if(can4) { // 4
			ret--;
			C[1]--;
		}
		else if(C[2]>=1) { // 2, 1+1
			C[2]--;
			C[1]-=2;
			ret++;
		}
		else if(C[1]>=4) { // 1+1 1+1
			C[1]-=4;
			ret+=2;
		}
		else { // 3+1
			C[1]--;
			ret++;
		}
	}
	// 1+2
	int m=min(C[1],C[2]);
	C[1]-=m;
	C[2]-=m;
	ret+=m;
	
	ret+=2*C[1]/3; // 1+1+1 for 2swap
	ret+=C[2]; // 2+2+2 for 3wrap
	return ret;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			did[i]=0;
		}
		vector<int> V;
		FOR(i,N) if(did[i]==0) {
			int cnt=0;
			x=i;
			while(did[x]==0) cnt++, did[x]=1, x=P[x];
			V.push_back(cnt);
		}
		
		ll pat=1;
		x=N;
		while(x>=5) {
			pat=pat*3%mo;
			x-=3;
		}
		pat=pat*x%mo;
		
		cout<<pat<<" "<<hoge(V)<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}