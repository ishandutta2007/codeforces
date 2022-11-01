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

int n;
lint ar[1000005];

lint fs[100005];
int cnt;

int divv[100005];
int main(){
	cin>>n;
	REP(i,n) ar[i]=readL();
	
	srand(time(NULL));
	random_shuffle(ar,ar+n);

	int C=min(n,10);

	lint res=1;
	REP(hoge,C){

		lint tmp=ar[hoge];
		cnt=0;
		for(lint i=1;i*i<=tmp;++i) if(tmp%i==0){
			fs[cnt++]=i;
			if(i*i!=tmp) fs[cnt++]=tmp/i;
		}
		sort(fs,fs+cnt);
		
		REP(i,cnt) divv[i]=0;

		REP(i,n) {
			lint g=__gcd(tmp,ar[i]);
			int p=lower_bound(fs,fs+cnt,g)-fs;
			++divv[p];
		}

		REP(i,cnt) REPN(j,cnt,i+1) if(fs[j]%fs[i]==0) divv[i]+=divv[j];

		REP(i,cnt) if(divv[i]*2>=n) chmax(res,fs[i]);
	}
	cout<<res<<endl;
	return 0;
}