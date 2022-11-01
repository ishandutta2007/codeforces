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
char s[105];
int seq[105];
int n;
lint dp[4][4][105];
lint rec(int prev,int begin,int ind){
	lint& res=dp[prev][begin][ind];
	if(res!=-1) return res;
	if(ind==n) {
		if(begin==1){
			if(seq[0]==0) return (prev==0 && seq[n-1]==1?1:0);
			else return (prev==1 && seq[n-1]==1?1:0);
		}
		if(prev==seq[n-1]) return 1;
		return 0;
	}
	if(prev==seq[ind-1]){
		if(prev==0){
			res=rec(0,begin,ind+1);
		}else{
			res=rec(0,begin,ind+1)+rec(1,begin,ind+1);
		}
	}else{
		if(prev==0){
			if(seq[ind]==0){
				if(ind+2<=n) res=rec(0,begin,ind+2)+rec(1,begin,ind+2);
				else{
					if(begin==0 || seq[0]==1) return 1;
					return 0;
				}
			}else res=0;
		}else{//prev==1 , seq[ind]==0
			if(ind==1){
				res=rec(0,begin,ind+1)+rec(1,begin,ind+1);
			}else res=0;
		}
	}

	return res;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s",s);
	n=strlen(s);
	REP(i,n) seq[i]=(s[i]=='A'?0:1);
	cout<<rec(0,0,1)+rec(1,1,1)<<endl;
	return 0;
}