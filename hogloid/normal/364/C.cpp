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


int k;
int maxfactor(int a){
	int res=1;
	for(int i=2;i*i<=a;++i) if(a%i==0){
		while(a%i==0) a/=i;
		res=i;
	}
	if(a>1) res=a;
	return res;
}

bool isprm(int a){
	if(maxfactor(a)==a) return true;
	return false;
}

vector<int> cand[1<<5];

int prm[5]={2,3,5,7,11};

int main(){
//	for(int k=10;k<=5000;++k){
		REP(i,1<<5) cand[i].clear();
	cin>>k;
	vector<int> canuse;
	canuse.pb(1);

	int m=0;
	for(int i=2;;++i) if(isprm(i)){
		
		REP(j,canuse.size()) if(canuse[j]*(lint)i<=2*k*k){
			canuse.pb(canuse[j]*i);
		}
		++m;
		if(canuse.size()>=k) {
			break;
		}
	}
	sort(ALL(canuse));
//	debug(ALL(canuse));
	
	REP(i,canuse.size()){
		int bit=0;
		REP(j,5) if(canuse[i]%prm[j]==0) bit|=(1<<j);
		cand[bit].pb(canuse[i]);
	}
	
	int cap=k;
	vector<int> ans;
	int cnt[5]={0};
	for(int i=m;i>=0;--i){

		REP(j,1<<m) if(__builtin_popcount(j)==i){
			int num=min(cap,(int)cand[j].size());
			cap-=num;
			REP(k,m) if(j>>k&1) cnt[k]+=num;
			REP(k,num) ans.pb(cand[j][k]);

			if(cap==0){

				REP(i,k) printf("%d%c",ans[i],i==k-1?'\n':' ');
				return 0;
			}
		}
	}

//	}

	


	return 0;
}