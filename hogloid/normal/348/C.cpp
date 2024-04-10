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

int n,m,q;
vector<int> S[100005];
vector<int> rev[100005];
lint ar[100005];

const int B=300;

int pos[100005];
vector<int> bigs;

lint add_set[100005];

int cov[400][100005];

lint tot_set[100005];
int main(){
	cin>>n>>m>>q;

	REP(i,n){
		int a;scanf("%d",&a);
		ar[i]=a;
	}

	int b=0;
	memset(pos,-1,sizeof(pos));
	REP(i,m){
		int k;scanf("%d",&k);
		REP(j,k){
			int a;scanf("%d",&a);--a;
			S[i].pb(a);
			tot_set[i]+=ar[a];

			rev[a].pb(i);
		}
		if(k>=B){
			pos[i]=b;
			bigs.pb(i);
			++b;
		}
	}
	REP(i,bigs.size()){
		int k=bigs[i];
		for(auto elem:S[k]){
			for(auto s:rev[elem]){
				++cov[i][s];
			}
		}
	}
	
	REP(hoge,q){
		char tmp[5];
		int k;
		scanf("%s%d",tmp,&k);
		--k;
		if(tmp[0]=='?'){
			lint res=0;
			if(S[k].size()>=B){
				res=tot_set[k];
			}else{
				for(auto elem:S[k]) res+=ar[elem];
				REP(i,bigs.size()) res+=cov[i][k]*add_set[bigs[i]];
			}
			printL(res);
			putchar('\n');
		}else{
			int x;scanf("%d",&x);
			
			if(S[k].size()>=B){
				add_set[k]+=x;
			}else{
				for(auto elem:S[k]) ar[elem]+=x;
			}
			REP(i,bigs.size()) tot_set[bigs[i]]+=cov[i][k]*(lint)x;
		}
	}

	return 0;
}