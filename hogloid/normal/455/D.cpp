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
const int B=100,SZ=100000/B+1;
int n;
int ar[100005];
vector<int> ar2[B+5];
int cnt[B+5][100005];


void build(){
	int c=0;
	REP(i,B+5) for(auto val:ar2[i]){
		ar[c++]=val;
		--cnt[i][val];
	}


	REP(i,B+5){
		ar2[i].clear();
		ar2[i].reserve(SZ);
	}
	REP(i,n){
		int blk=i/SZ;
		ar2[blk].pb(ar[i]);
		++cnt[blk][ar[i]];
	}
}


int erase(int p){
	int cur=0;
	REP(i,B+5){
		if(cur<=p && p<cur+ar2[i].size()){
			int res=ar2[i][p-cur];

			ar2[i].erase(ar2[i].begin()+p-cur);
			--cnt[i][res];
			return res;
		}
		cur+=ar2[i].size();
	}
}
void insert(int p,int k){
	int cur=0;
	REP(i,B+5){
		if(cur<=p && p<=cur+ar2[i].size()){
			ar2[i].insert(ar2[i].begin()+p-cur,k);
			++cnt[i][k];
			if(ar2[i].size()>SZ*2.5) build();
			break;
		}
		cur+=ar2[i].size();
	}
}


int main(){
	cin>>n;
	REP(i,n) scanf("%d",&ar[i]);

	build();

	int q;cin>>q;
	int lans=0;
	REP(hoge,q){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);
		l=(l+lans-1)%n;
		r=(r+lans-1)%n;

		if(l>r) swap(l,r);
		//[l...r]
		
		if(t==1){
			int v=erase(r);
			insert(l,v);
		}else{
			int k;scanf("%d",&k);
			k=(k+lans-1)%n+1;
			
			int cur=0;
			int res=0;
			REP(i,B+5){
				if(l<=cur && cur+ar2[i].size()<=r+1){
					res+=cnt[i][k];
				}else if(r+1<=cur || cur+ar2[i].size()<=l) ;
				else{
					REP(j,ar2[i].size()){
						if(l<=cur+j && cur+j<=r && ar2[i][j]==k) ++res;
					}
				}
				cur+=ar2[i].size();
			}
			printf("%d\n",res);
			lans=res;
		}
	}


	return 0;
}