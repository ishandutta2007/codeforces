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

int Q;
int M[101010];
const int DI=330;

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,int pos=29) {
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,pos-1);
		}
		else {
			v=s;
		}
	}
	ll pick(int mask,int left,int pos=29) {
		if(pos<0) {
			return v;
		}
		
		if(left&(1<<pos)) {
			if(mask&(1<<pos)) {
				if(nex[0]) {
					ll ret=nex[0]->pick(mask,(1<<30)-1,pos-1);
					if(ret>=0) return ret;
				}
				if(nex[1]) return nex[1]->pick(mask,left^(1<<pos),pos-1);
			}
			else {
				if(nex[1]) {
					ll ret=nex[1]->pick(mask,left^(1<<pos),pos-1);
					if(ret>=0) return ret;
				}
				if(nex[0]) return nex[0]->pick(mask,(1<<30)-1,pos-1);
			}
		}
		else {
			if(nex[0]) return nex[0]->pick(mask,left,pos-1);
		}
		return -1;
		
	}
};

BinarySumTrie root[DI];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			if(M[x]==0) {
				M[x]=1;
				for(i=1;i<=DI;i++) if(x%i==0) root[i].add(x);
			}
		}
		else {
			int X,K,S;
			cin>>X>>K>>S;
			if(X%K || S<X) {
				cout<<-1<<endl;
				continue;
			}
			if(K>=DI) {
				int best=-1,xm=-1;
				for(x=K;X+x<=S;x+=K) if(M[x] && (X^x)>xm) xm=X^x, best=x;
				cout<<best<<endl;
			}
			else {
				int ret=root[K].pick(X,S-X);
				cout<<ret<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}