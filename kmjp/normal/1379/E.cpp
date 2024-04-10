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

int N,K;

int P[202020];
int nex;
map<int,int> memo[201010];

int ok(int N,int K) {
	if(N%2==0) return 0;
	if(K>max(0,(N-3)/2)) return 0;
	
	if(memo[N].count(K)) return memo[N][K];
	
	if(N==1) return memo[N][K]=K==0;
	if(N==3) return memo[N][K]=K==0;
	
	
	
	if(K==0) {
		if((N&(N+1))==0) return memo[N][K]=1;
	}
	else if(K==1) {
		int a=0;
		while(1<<(a+1)<N) a++;
		int c=(1<<(a-1))-1;
		int d=N-1-c;
		if(c&&d&&ok(c,0)&&ok(d,0)&&min(c,d)*2<=max(c,d)) return memo[N][K]=c;
		if(c&&d&&ok(c,0)&&ok(d,1)&&min(c,d)*2>max(c,d)) return memo[N][K]=c;
		c=(1<<a)-1;
		d=N-1-c;
		if(c&&d&&ok(c,0)&&ok(d,0)&&min(c,d)*2<=max(c,d)) return memo[N][K]=c;
		if(c&&d&&ok(c,0)&&ok(d,1)&&min(c,d)*2>max(c,d)) return memo[N][K]=c;
		
	}
	else {
		if(ok(N-2,K-1)) return memo[N][K]=1;
	}
	return memo[N][K]=0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	x=8;
	for(x=8;x<=N;x*=2) {
		memo[x+3][3]=3;
		if(x>=16) {
			memo[x+1][2]=3;
		}
	}
	
	
	/*
	for(x=1;x<=37;x+=2) {
		cout<<x<<" : ";
		for(y=0;y*2+1<=x;y++) cout<<ok(x,y);
		cout<<endl;
	}
	*/
	
	if(ok(N,K)) {
		int cur=1;
		
		while(cur<=N) {
			x=ok(N+1-cur,K);
			//cout<<(N-cur+1)<<" "<<cur<<" "<<K<<" "<<x<<endl;
			assert(x>0);
			if(K==0) {
				queue<int> Q;
				Q.push(cur);
				while(cur<=N) {
					x=Q.front();
					Q.pop();
					P[cur+1]=P[cur+2]=x;
					Q.push(cur+1);
					Q.push(cur+2);
					cur+=2;
				}
				break;
			}
			else if(K>=2 && x==1) {
				P[cur+1]=P[cur+2]=cur;
				K--;
				cur+=2;
			}
			else {
				int num=N+1-cur;
				int c=memo[num][K];
				int d=num-c;
				if(min(c,d)*2<max(c,d)) K--;
				P[cur+1]=P[cur+1+c]=cur;
				queue<int> Q;
				c--;
				Q.push(cur+1);
				cur++;
				while(c) {
					x=Q.front();
					Q.pop();
					P[cur+1]=P[cur+2]=x;
					Q.push(cur+1);
					Q.push(cur+2);
					cur+=2;
					c-=2;
				}
				cur++;
			}
			
		}
		
		cout<<"YES"<<endl;
		FOR(i,N) cout<<P[i+1]<<" ";
		cout<<endl;
		
		
	}
	else {
		cout<<"NO"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}