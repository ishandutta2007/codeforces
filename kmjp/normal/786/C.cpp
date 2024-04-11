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

int N,ON;
int A[101010];
int pre[101010],nex[101010];
int id[101010];
int R[101010],cnt[101010];
int num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ON=N;
	MINUS(id);
	FOR(i,N) {
		cin>>A[i];
		if(i && A[i]==A[i-1]) {
			i--;
			N--;
			continue;
		}
		pre[i]=id[A[i]];
		id[A[i]]=i;
		cnt[i]=1;
		R[i]=i+1;
	}
	FOR(i,101010) id[i]=N;
	for(i=N-1;i>=0;i--) {
		nex[i]=id[A[i]];
		id[A[i]]=i;
	}
	
	
	for(i=1;i<=ON;i++) {
		
		int cur=0;
		int step=0;
		while(cur<N) {
			step++;
			while(cnt[cur]<=i && R[cur]<N) {
				x=R[cur];
				if(cnt[cur]==i && pre[x]<cur) break;
				
				if(nex[x]>=R[x]) cnt[x]--;
				if(cnt[x]) {
					swap(cnt[x+1],cnt[x]);
					R[x+1]=R[x];
				}
				R[cur]++;
				if(pre[R[cur]]<cur) cnt[cur]++;
			}
			cur=R[cur];
		}
		
		cout<<step;
		if(i<ON) cout<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}