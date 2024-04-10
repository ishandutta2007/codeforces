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

int m,n;

pair<int,pi> eve[100005];
lint len[100005];

int ar[100005];
int main(){
	cin>>m;
	len[0]=0;
	REP(i,m){
		int t;scanf("%d",&t);
		if(t==1){
			int a;scanf("%d",&a);
			eve[i]=mp(t,mp(a,-1));
			if(len[i]<100005) ar[len[i]]=a;
			len[i+1]=len[i]+1;
		}else{
			int a,b;scanf("%d%d",&a,&b);
			eve[i]=mp(t,mp(a,b));

			len[i+1]=len[i]+a*(lint)b;
			for(lint j=len[i];j<min(len[i+1],100005ll);++j) ar[j]=ar[(j-len[i])%a];
		}
	}

	cin>>n;
	REP(hoge,n){
		lint p=readL();--p;

		int q=upper_bound(len,len+m+1,p)-len;
		--q;

		int res;
		if(eve[q].fr==1){
			res=eve[q].sc.fr;
		}else{
			lint dif=p-len[q];
			dif%=eve[q].sc.fr;
			res=ar[dif];
		}
		printL(res);
		putchar('\n');
	}






	return 0;
}