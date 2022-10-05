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
pair<ll,ll> P[303030];
ll T[303030],W[303030];
ll MT,MW;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N--;
	cin>>MT>>MW;
	priority_queue<ll> Q;
	FOR(i,N) {
		cin>>T[i]>>W[i];
		if(T[i]>MT) {
			Q.push(-(W[i]-T[i]+1));
			N--;
			i--;
			continue;
		}
		P[i]={T[i],W[i]-T[i]+1};
	}
	P[N]={0,0};
	N++;
	sort(P,P+N);
	reverse(P,P+N);
	
	int be=Q.size()+1;
	ll left=0;
	FOR(i,N) {
		left += MT-P[i].first;
		MT=P[i].first;
		while(Q.size() && -Q.top()<=left) {
			left += Q.top();
			Q.pop();
		}
		
		be=min(be,(int)Q.size()+1);
		Q.push(-P[i].second);
	}
	cout<<be<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}