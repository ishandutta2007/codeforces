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

const int INF=5e8;
char s[50000];
int n,m;

map<pi,int> memo;

static const int C=27;
static const int MX=C*C*C*C+5;
vector<int> app[MX];
int main(){
	scanf("%s",s);
	n=strlen(s);

	REP(i,n) {
		int hash=0;
		REP(j,4) if(i+j<n){
			hash=hash*C+s[i+j]-'a'+1;
			app[hash].pb(i);
		}
	}
	
	cin>>m;
	REP(hoge,m){
		dump(hoge);
		char a[5],b[5];
		scanf("%s%s",a,b);

		int lena=strlen(a),lenb=strlen(b);
		
		int A=0,B=0;
		REP(i,lena) A=A*C+a[i]-'a'+1;
		REP(i,lenb) B=B*C+b[i]-'a'+1;
		
		int res;
		if(mp(app[A].size(),A)>mp(app[B].size(),B)) swap(A,B),swap(lena,lenb);
		if(app[A].size()>=100){
			if(memo.count(mp(A,B))) res=memo[mp(A,B)];
			else{
				int i=0,j=0;
				res=INF;
				while(i<app[A].size() && j<app[B].size()){
					chmin(res,max(app[A][i]+lena,app[B][j]+lenb)-min(app[B][j],app[A][i]));
					if(app[A][i]<app[B][j]) ++i;
					else ++j;
				}
				memo[mp(A,B)]=res;
			}
		}else{
			if(app[B].size()<=100){
				int i=0,j=0;
				res=INF;
				while(i<app[A].size() && j<app[B].size()){
					dump(i);dump(j);
					dump(app[A][i]);dump(app[B][j]);
					chmin(res,max(app[A][i]+lena,app[B][j]+lenb)-min(app[B][j],app[A][i]));
					if(app[A][i]<app[B][j]) ++i;
					else ++j;
				}
			}else{
				res=INF;
				REP(i,app[A].size()){
					int lb=lower_bound(ALL(app[B]),app[A][i])-app[B].begin();
					if(lb<app[B].size()) chmin(res,max(app[A][i]+lena,app[B][lb]+lenb)-
												min(app[B][lb],app[A][i]));
					--lb;
					if(lb>=0) chmin(res,max(app[A][i]+lena,app[B][lb]+lenb)-
												min(app[B][lb],app[A][i]));
				}
			}
		}
		if(res==INF) res=-1;
		printf("%d\n",res);

	}





	return 0;
}