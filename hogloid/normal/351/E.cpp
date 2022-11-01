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
int ar[2005];

pi ar2[2005];

int done[2005];
int main(){
	cin>>n;
	REP(i,n){
		cin>>ar[i];
		ar[i]=abs(ar[i]);
		ar2[i]=mp(ar[i],i);
	}
	sort(ar2,ar2+n,greater<pi>());
	int res=0;
	REP(i,n){
		int j=i;
		while(j<n && ar2[i].fr==ar2[j].fr){
			int p=ar2[j].sc;
			done[p]=1;
			++j;
		}
		REPN(k,j,i){
			int L=0,R=0;
			int p=ar2[k].sc;
			REP(l,p) if(!done[l]) ++L;
			REPN(l,n,p+1) if(!done[l]) ++R;
			
			res+=min(L,R);
		}
		i=j-1;
	}
	cout<<res<<endl;
	return 0;
}