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

int n,m,p;
int ar[200005],b[200005];

map<int,int> bnum;
map<int,int> curnum;


int same;
void fix(int i,int add){
	if(bnum.count(i)==0) return;
	if(curnum[i]==bnum[i]) --same;
	curnum[i]+=add;
	if(curnum[i]==bnum[i]) ++same;
}


int main(){
	cin>>n>>m>>p;

	REP(i,n) scanf("%d",&ar[i]);
	REP(i,m){
		scanf("%d",&b[i]);
		bnum[b[i]]++;
	}


	p=min(p,n);
	
	vector<int> res;
	REP(i,p){
		int cnt=0;
		curnum.clear();
		same=0;
		for(int j=i;j<n;j+=p,++cnt){
			if(cnt>=m){
				fix(ar[j-m*p],-1);
			}
			fix(ar[j],1);

			if(same==bnum.size()) res.pb(j-(m-1)*p);
		}
	}
	sort(ALL(res));
	cout<<res.size()<<endl;
	REP(i,res.size()) printf("%d\n",res[i]+1);




	return 0;
}