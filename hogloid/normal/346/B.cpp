#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;


char s[105],t[105],v[105];
int dp[105][105][105];
pair<pi,int> back[105][105][105];
int n,m,l;

int table[105];
void KMP(char* key){
	int klen=strlen(key);
	table[0]=0;
	REPN(i,klen+1,1){
		int j=table[i-1];
		while(j>0 && key[j]!=key[i]) j=table[j-1];
		if(key[j]==key[i]) ++j;
		table[i]=j;
	}
}
void update(int a,int b,int c,int x,int y,int z,int add){
	if(dp[a][b][c]<dp[x][y][z]+add){
		dp[a][b][c]=dp[x][y][z]+add;
		back[a][b][c]=mp(mp(x,y),z);
	}
}

int main(){
	scanf("%s%s%s",s,t,v);
	n=strlen(s);m=strlen(t);l=strlen(v);
	
	KMP(v);

	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;

	int res=-1,x,y,z;
	REP(i,n+1) REP(j,m+1) REP(k,l) if(dp[i][j][k]>=0){
		if(res<dp[i][j][k]){
			res=dp[i][j][k];
			x=i;y=j;z=k;
		}
		if(i<n && j<m){
			if(s[i]==t[j]){
				int k2=k;
				while(k2>0 && v[k2]!=s[i]) k2=table[k2-1];
				if(v[k2]==s[i]) ++k2;

				update(i+1,j+1,k2,i,j,k,1);
			}
		}
		if(i<n) update(i+1,j,k,i,j,k,0);
		if(j<m) update(i,j+1,k,i,j,k,0);
	}

	if(res==0){
		puts("0");
		return 0;
	}
	string ans;
	while(x+y+z>0){
		pair<pi,int> nxt=back[x][y][z];
		int a=nxt.fr.fr,b=nxt.fr.sc,c=nxt.sc;

		if(dp[a][b][c]<dp[x][y][z]) ans+=s[a];

		x=a;y=b;z=c;
	}
	reverse(ALL(ans));
	cout<<ans<<endl;

	return 0;
}