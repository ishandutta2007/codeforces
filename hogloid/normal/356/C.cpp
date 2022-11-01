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

int cnt[10];
int main(){
	cin>>n;
	int sum=0;
	REP(i,n){
		int a;scanf("%d",&a);
		sum+=a;
		++cnt[a];
	}
	if(sum<=2 || sum==5){
		puts("-1");
		return 0;
	}

	
	int res=0;
	int tmp=min(cnt[1],cnt[2]);
	cnt[3]+=tmp;
	cnt[1]-=tmp;
	cnt[2]-=tmp;

	res+=tmp;

	if(cnt[1]>0){
		res+=cnt[1]/3*2;
		cnt[3]+=cnt[1]/3;

		int rest=cnt[1]%3;
		cnt[1]=rest;
		
		if(rest==1){
			if(cnt[3]>0) ++res;
			else res+=2;
		}else if(rest==2){
			if(cnt[3]>=2) res+=2;
			else if(cnt[4]>=1) res+=2;
			else ;//never happen
		}
	}else if(cnt[2]>0){
		res+=cnt[2]/3*2;
		cnt[3]+=cnt[2]/3*2;

		int rest=cnt[2]%3;
		cnt[2]=rest;

		if(rest==1){
			if(cnt[4]>0) ++res;
			else res+=2;
		}else if(rest==2){
			res+=2;
		}
	}

	cout<<res<<endl;

	return 0;
}