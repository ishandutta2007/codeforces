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


int n,p,q;
pair<pi,int> ar[4005];//((cost,hap),time)

int zip[4005],zn;

typedef pair<pi,pi> qt;
vector<qt> query;
int ans[20005];
bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
	return a.sc<b.sc;
}

int dp1[4005][4005],dp2[4005][4005];
void rec(int l,int r,vector<qt> query){
	prl;
	if(r-l==1){
		REP(i,query.size()){
			dump(i);
			if(query[i].fr.fr<=ar[l].sc && ar[l].sc<query[i].fr.sc){
				if(query[i].sc.fr>=ar[l].fr.fr){
					ans[query[i].sc.sc]=ar[l].fr.sc;
				}
			}
		}
		return;
	}
	dump(l);dump(r);
	vector<qt> L,R;
	int md=(l+r)>>1;
	
	{
		int len=r-md;
		REP(i,len+1) REP(j,4005) dp1[i][j]=-1;
		dp1[0][0]=0;
		REP(i,len) REP(j,4005) if(dp1[i][j]>=0){
			chmax(dp1[i+1][j],dp1[i][j]);
			int indx=i+md;
			if(j+ar[indx].fr.fr<=4000) chmax(dp1[i+1][j+ar[indx].fr.fr],dp1[i][j]+ar[indx].fr.sc);
		}
	}
	prl;
	{
		int len=md-l;
		REP(i,len+1) REP(j,4005) dp2[i][j]=-1;
		dp2[0][0]=0;
		REP(i,len) REP(j,4005) if(dp2[i][j]>=0){
			chmax(dp2[i+1][j],dp2[i][j]);
			int indx=md-1-i;
			if(j+ar[indx].fr.fr<=4000) chmax(dp2[i+1][j+ar[indx].fr.fr],dp2[i][j]+ar[indx].fr.sc);
		}
	}
	prl;

	REP(i,query.size()){
		dump(query[i]);
		if(query[i].fr.sc<=ar[md].sc) L.pb(query[i]);
		else if(ar[md].sc<query[i].fr.fr) R.pb(query[i]);
		else{
			int rlen=r-md,llen=md-l;
			int r2=0,l2=0;
			while(r2<rlen && ar[md+r2].sc<query[i].fr.sc) ++r2;
			while(l2<llen && ar[md-1-l2].sc>=query[i].fr.fr) ++l2;

			REP(j,4000){
				chmax(dp1[r2][j+1],dp1[r2][j]);
				chmax(dp2[l2][j+1],dp2[l2][j]);
			}

			int b=query[i].sc.fr;
			int res=0;
			REP(j,b+1) if(dp1[r2][j]>=0 && dp2[l2][b-j]>=0){
				chmax(res,dp1[r2][j]+dp2[l2][b-j]);
			}
			ans[query[i].sc.sc]=res;
		}
	}
	rec(l,md,L);
	rec(md,r,R);
}
int main(){
	cin>>n>>p;
	REP(i,n){
		int c,h,t;cin>>c>>h>>t;
		ar[i]=mp(mp(c,h),t);

		zip[i]=t;
	}
	sort(ar,ar+n,cmp);
	sort(zip,zip+n);
	zn=unique(zip,zip+n)-zip;
	prl;

	REP(i,n) {
		ar[i].sc=lower_bound(zip,zip+zn,ar[i].sc)-zip;
		dump(ar[i]);
	}

	prl;
	cin>>q;
	REP(i,q){
		int a,b;cin>>a>>b;
		int l=a-p,r=a;
		l=upper_bound(zip,zip+zn,l)-zip;
		r=upper_bound(zip,zip+zn,r)-zip;//[l...r)

		dump(l);dump(r);
		
		query.pb(mp(mp(l,r),mp(b,i)));
	}
	prl;

	prl;
	rec(0,n,query);

	REP(i,q) printf("%d\n",ans[i]);





	return 0;
}