#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,k;
int q[105],rev[105],s[105];
int cur[105],tmp[105];
int match[205];
bool solve(){
	REP(i,n) cur[i]=i;
	REP(hoge,k){
		REP(i,n) tmp[q[i]]=cur[i];
		REP(i,n) cur[i]=tmp[i];
	}
	REP(hoge,k*2+1){
		match[hoge]=1;
		REP(i,n) if(cur[i]!=s[i]) match[hoge]=0;
		REP(i,n) tmp[i]=cur[q[i]];
		REP(i,n) cur[i]=tmp[i];
	}
	if(match[k]) return false;
	REP(i,k*2+1) if(i!=k && match[i] && i%2==0){
		if(i==k+1){
			if(k==1) return true;
			if(match[k-1]==0) return true;
			continue;
		}
		if(i==k-1){
			if(k==1) return true;
			if(match[k+1]==0) return true;
			continue;
		}

		int fail=0;
		if(i<k){
			REPN(j,k+1,i+1) if(match[j]) fail=1;
		}else{
			REPN(j,i,k) if(match[j]) fail=1;
		}
		if(!fail) return true;
	}

	return false;
}


int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>q[i],--q[i];
		rev[q[i]]=i;
	}
	REP(i,n) cin>>s[i],--s[i];

	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}