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

int n,s;

typedef vector<int> vi;
typedef bitset<70005> bits;
int ar[70005];

int max_id;

bits rec2(int l,int r){
	bits res;
	res.set(0);

	REPN(i,r,l) if(i!=max_id){
		res|=(res<<ar[i]);
	}

	return res;
}

bits dp[2005];
vi rec1(int l,int r,int goal){
	if(r-l==1){
		if(goal>0){
			if(max_id==l || ar[l]!=goal) return vi(1,-1);
			else return vi(1,l);
		}
		return vi(0);
	}
	if(r-l<=2000){
		REP(i,r-l+1) dp[i].reset();

		dp[0].set(0);
		REP(i,r-l){
			if(i+l!=max_id){
				dp[i+1]=(dp[i]|(dp[i]<<ar[i+l]));
			}else dp[i+1]=dp[i];
		}
		
		if(dp[r-l].test(goal)==false) return vi(1,-1);

		int cur=goal;
		vi res;
		for(int i=r-l-1;i>=0;--i){
			if(dp[i].test(cur) || i+l==max_id) ;
			else {
				res.pb(i+l);
				cur-=ar[i+l];
			}
		}
		reverse(ALL(res));
		return res;
	}

	int md=(l+r)>>1;
	bits L=rec2(l,md),R=rec2(md,r);
	REP(i,goal+1) if(L.test(i) && R.test(goal-i)){
		vi left=rec1(l,md,i),right=rec1(md,r,goal-i);

		REP(j,right.size()) left.pb(right[j]);
		return left;
	}
	return vi(1,-1);
}

bool cmp(int a,int b){
	return ar[a]<ar[b];
}

vi inside;
vi cont[70005];
int main(){
	cin>>n>>s;
	REP(i,n) scanf("%d",&ar[i]);
	
	max_id=max_element(ar,ar+n)-ar;
	
	s-=ar[max_id];


	if(s<0) return puts("-1"),0;

	vector<int> res=rec1(0,n,s);
	debug(ALL(res));

	if(res.size()==1 && res[0]==-1) return puts("-1"),0;

	res.pb(max_id);
	
	sort(ALL(res));

	REP(i,n) if(!binary_search(ALL(res),i)){
		inside.pb(i);
	}
	prl;
	sort(ALL(inside),cmp);
	inside.pb(max_id);
	prl;
	for(int i=inside.size()-1;i>0;--i) cont[inside[i]].pb(inside[i-1]);


	prl;
	REP(i,n){
		int own=ar[i];
		REP(j,cont[i].size()) own-=ar[cont[i][j]];
		printf("%d %d",own,(int)cont[i].size());
		REP(j,cont[i].size()) printf(" %d",cont[i][j]+1);
		putchar('\n');
	}
	return 0;
}