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

string S;
ll N,X,Y;
ll L[101010][2],R[101010][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X>>Y;
	N=S.size();
	ll ma=1LL<<60;
	ll base=0;
	FOR(i,N) {
		L[i+1][0]=L[i][0];
		L[i+1][1]=L[i][1];
		if(S[i]=='0') {
			base+=1LL*L[i+1][1]*Y;
			L[i+1][0]++;
		}
		else if(S[i]=='1') {
			base+=1LL*L[i+1][0]*X;
			L[i+1][1]++;
		}
	}
	for(i=N-1;i>=0;i--) {
		R[i+1][0]=R[i+2][0];
		R[i+1][1]=R[i+2][1];
		if(S[i]=='0'||S[i]=='1') R[i+1][S[i]-'0']++;
	}
	ll add=1LL<<60;
	ll sum[2]={};
	int num=0;
	FOR(i,N) if(S[i]=='?') {
		sum[0]+=L[i+1][1]*Y;
		sum[0]+=R[i+1][1]*X;
		sum[1]+=L[i+1][0]*X;
		sum[1]+=R[i+1][0]*Y;
		num++;
	}
	add=min(sum[0],sum[1]);
	int cnt=0;
	FOR(i,N) if(S[i]=='?') {
		//01
		sum[0]-=L[i+1][1]*Y;
		sum[0]+=L[i+1][0]*X;
		sum[0]-=R[i+1][1]*X;
		sum[0]+=R[i+1][0]*Y;
		sum[0]+=(num-(cnt+1))*Y;
		sum[0]-=cnt*Y;
		sum[1]-=L[i+1][0]*X;
		sum[1]+=L[i+1][1]*Y;
		sum[1]-=R[i+1][0]*Y;
		sum[1]+=R[i+1][1]*X;
		sum[1]+=(num-(cnt+1))*X;
		sum[1]-=cnt*X;
		add=min(add,sum[0]);
		add=min(add,sum[1]);
		cnt++;
	}
	cout<<base+add<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}