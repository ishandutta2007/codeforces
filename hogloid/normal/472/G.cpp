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
typedef unsigned long long int lint;
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
	scanf("%I32d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I32d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;

unsigned int bit1[70][10000],bit2[70][10000];
int len1,len2;
char tmp[200005];
void read(unsigned int bit[70][10000],int &len){
	scanf("%s",tmp);
	len=strlen(tmp);

	REP(i,32){
		REPN(j,len,i) if(tmp[j]=='1'){
			bit[i][(j-i)/32]|=(1<<((j-i)%32));
		}
	}
}

int cnt[1<<16];
int mask=(1<<16)-1;
inline int count(const unsigned int & a){
	return cnt[a&mask]+cnt[a>>16];
}
int main(){
	REP(i,1<<16) cnt[i]=__builtin_popcount(i);
	read(bit1,len1);
	read(bit2,len2);

	int q;scanf("%d",&q);
	REP(hoge,q){
		int p1,p2,l;scanf("%d%d%d",&p1,&p2,&l);
		
		int r1=p1%32,r2=p2%32;
		int st1=(p1-r1)/32,st2=(p2-r2)/32;
		int block=l/32,rest=l%32;

		int res=0;
		REP(i,block) res+=count(bit1[r1][i+st1]^bit2[r2][i+st2]);
		res+=count((bit1[r1][st1+block]^bit2[r2][st2+block])&((1ll<<rest)-1));
		printf("%d\n",res);
	}

	return 0;
}