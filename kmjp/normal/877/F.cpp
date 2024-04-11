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

int N,K,Q;
int A[101010];
ll S[101010];
map<ll,vector<int>> V;
int L[101010],R[101010];
const int DI=350;
ll ret[101010];
vector<pair<int,int>> ev[404];

vector<int>* VR[101010];
vector<int>* VL[101010];
vector<int>::iterator VLp[101010];
vector<int>::iterator VRp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++) scanf("%d",&A[i]);
	V[0].push_back(0);
	for(i=1;i<=N;i++) {
		scanf("%d",&x);
		if(A[i]==1) A[i]=x;
		else A[i]=-x;
		S[i]=S[i-1]+A[i];
		V[S[i]].push_back(i);
	}
	FOR(i,N+1) {
		if(V.count(S[i]-K)) {
			VR[i]=&V[S[i]-K];
			VRp[i]=lower_bound(VR[i]->begin(),VR[i]->end(),i);
		}
		if(V.count(S[i]+K)) {
			VL[i]=&V[S[i]+K];
			VLp[i]=lower_bound(VL[i]->begin(),VL[i]->end(),i+1);
		}
		
	}
	
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d%d",&L[i],&R[i]);
		ev[L[i]/DI].push_back({R[i],i});
	}
	
	FOR(i,350) if(ev[i].size()) {
		sort(ALL(ev[i]));
		
		int LL=i*DI,RR=LL;
		ll num=0;
		FORR(e,ev[i]) {
			int LE=L[e.second]-1,RE=e.first;
			while(RR<RE) {
				RR++;
				if(VR[RR]) num += VRp[RR]-lower_bound(VR[RR]->begin(),VR[RR]->end(),LL);
			}
			while(LL<LE) {
				if(VL[LL]) num -= lower_bound(VL[LL]->begin(),VL[LL]->end(),RR+1)-VLp[LL];
				LL++;
			}
			while(LE<LL) {
				LL--;
				if(VL[LL]) num += lower_bound(VL[LL]->begin(),VL[LL]->end(),RR+1)-VLp[LL];
			}
			ret[e.second]=num;
		}
	}
	
	
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}