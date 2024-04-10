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
int ar[300005];
set<int> exi;

pi ar2[300005];

const int C=60;

double get(const vector<int>& a){
	double res=0,div=1;;
	REP(i,a.size()-1){
		res+=(a[i+1]-a[i])/div;
		div*=2;
	}
	return res;
}
vector<int> refl(vector<int>& a){
	REP(i,a.size()) a[i]*=-1;
	return a;
}

double getval(int p){
	auto it=exi.find(p);
	vector<int> R,L;
	R.pb(*it);
	++it;
	while(it!=exi.end()){

		if(R.size()>C) break;
		R.pb(*it);
		++it;
	}
	R.pb(n);

	it=exi.find(p);
	L.pb(*it);
	while(it!=exi.begin()){
		if(L.size()>C) break;
		--it;
		L.pb(*it);
	}
	L.pb(-1);

	double sum1=get(R),sum2=get(refl(L));

	exi.erase(p);
	return sum1*sum2/2;
}

int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&ar[i]);
		ar2[i]=mp(ar[i],i);
	}
	REP(i,n) exi.insert(i);
	prl;
	sort(ar2,ar2+n);
	double res=0;
	REP(i,n){
		int p=ar2[i].sc;
		double t=getval(p);
		res+=t*ar2[i].fr;
	}
	res/=n*(lint)n;
	printf("%.10f\n",res);


	return 0;
}