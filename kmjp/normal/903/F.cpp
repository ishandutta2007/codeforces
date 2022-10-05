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

int W;
int A[4];
int mask[1010];
string S[4];

int from[1<<16];
int to[1<<16];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W;
	FOR(i,4) cin>>A[i];
	FOR(i,4) {
		cin>>S[i];
		FOR(j,W) if(S[i][j]=='.') mask[j] |= 1<<i;
		FOR(j,4) mask[W+j] |= 1<<i;
	}
	
	FOR(i,1<<16) from[i]=1LL<<30;
	int cmask=mask[0] | (mask[1]<<4) | (mask[2]<<8) | (mask[3]<<12);
	from[cmask]=0;
	FOR(x,W) {
		FOR(cmask,1<<16) {
			from[cmask | ((1<<16)-1)]=min(from[cmask | ((1<<16)-1)],from[cmask]+A[3]);
			from[cmask | (7<<0)|(7<<4)|(7<<8)]=min(from[cmask | (7<<0)|(7<<4)|(7<<8)],from[cmask]+A[2]);
			from[cmask | (7<<1)|(7<<5)|(7<<9)]=min(from[cmask | (7<<1)|(7<<5)|(7<<9)],from[cmask]+A[2]);
			from[cmask | (3<<0)|(3<<4)]=min(from[cmask | (3<<0)|(3<<4)],from[cmask]+A[1]);
			from[cmask | (3<<1)|(3<<5)]=min(from[cmask | (3<<1)|(3<<5)],from[cmask]+A[1]);
			from[cmask | (3<<2)|(3<<6)]=min(from[cmask | (3<<2)|(3<<6)],from[cmask]+A[1]);
			from[cmask | (1<<0)]=min(from[cmask | (1<<0)],from[cmask]+A[0]);
			from[cmask | (1<<1)]=min(from[cmask | (1<<1)],from[cmask]+A[0]);
			from[cmask | (1<<2)]=min(from[cmask | (1<<2)],from[cmask]+A[0]);
			from[cmask | (1<<3)]=min(from[cmask | (1<<3)],from[cmask]+A[0]);
			to[cmask]=1LL<<30;
		}
		
		FOR(cmask,1<<12) {
			to[cmask|(mask[x+4]<<12)]=min(to[cmask|(mask[x+4]<<12)],from[(cmask<<4)|0xF]);
		}
		swap(from,to);
	}
	cout<<to[(1<<16)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}