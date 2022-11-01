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


int C=26;
int n;
char s[300005];
int nxt[30][300005];

int pos[30];
lint res[30];
int main(){
	scanf("%s",s);
	n=strlen(s);
	REP(i,C) nxt[i][n]=n;
	for(int i=n-1;i>=0;--i){
		REP(j,C){
			nxt[j][i]=nxt[j][i+1];
			if(s[i]-'a'==j) nxt[j][i]=i;

			pos[j]=nxt[j][i];
		}
		pos[C]=n;
		sort(pos,pos+C+1);
		REP(j,C){
			res[j+1]+=pos[j+1]-pos[j];
		}
	}

	int diver=0;
	REP(j,C+1) if(res[j]>0) diver=j;

	cout<<diver<<endl;
	REP(j,diver) cout<<res[j+1]<<endl;



	return 0;
}