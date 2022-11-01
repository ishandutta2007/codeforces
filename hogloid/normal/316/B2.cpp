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

int n;
int nxt[1005],lat[1005];

vector<int> group;
int vis[1005];

int able[1005];
int main(){
	int x;
	cin>>n>>x;

	--x;
	memset(nxt,-1,sizeof(nxt));
	memset(lat,-1,sizeof(lat));
	REP(i,n){
		cin>>nxt[i];--nxt[i];
		if(nxt[i]!=-1) lat[nxt[i]]=i;
	}


	REP(i,n) if(!vis[i] && lat[i]==-1){
		int num=1;
		int cur=i;

		int isX=0;
		if(i==x) isX=1;
		vis[i]=1;
		while(nxt[cur]!=-1){
			cur=nxt[cur];
			vis[cur]=1;
			if(cur==x) isX=1;
			++num;
		}
		if(!isX) group.pb(num);
	}

	int add=0;
	int cur=x;
	while(nxt[cur]!=-1){
		cur=nxt[cur];
		++add;
	}

	
	able[0]=1;
	REP(i,group.size()) for(int j=n;j>=0;--j) if(able[j]){
		able[j+group[i]]=1;
	}

	REP(i,n+1) if(able[i]){
		printf("%d\n",i+add+1);
	}

}