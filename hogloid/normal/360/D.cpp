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
int ar1[10005],ar2[100005];

lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%p;
		a=a*a%p;
		k>>=1;
	}
	return res;
}

int done[10005];

int phi(int a){
	int res=a;
	for(int i=2;i*i<=a;++i) if(a%i==0){
		res=(res/i*(i-1));
		while(a%i==0) a/=i;
	}
	if(a>1) res=res/a*(a-1);

	return res;
}


int main(){
	cin>>n>>m>>p;
	REP(i,n) cin>>ar1[i];
	REP(i,m) scanf("%d",&ar2[i]);
	
	vector<int> divs;
	for(int i=1;i*i<=p-1;++i) if((p-1)%i==0){
		divs.pb(i);
		if(i*i!=p-1) divs.pb((p-1)/i);
	}
	sort(ALL(divs));
	
	debug(ALL(divs));
	lint mod=p-1;

	vector<int> nums;
	REP(i,divs.size()){
		int k=divs[i];
		REP(j,n) if(!done[j]){
			if(mpow(ar1[j],k)==1){
				nums.pb(k);
				done[j]=1;
			}
		}
	}
	debug(ALL(nums));
	
	int gsum=mod;
	REP(i,m) gsum=__gcd(gsum,ar2[i]);
	
	set<int> num2;
	REP(i,nums.size()){
		int k=nums[i];
		
		int g=__gcd(gsum,k);
		num2.insert((p-1)/(k/g));
	}
	
	int res=0;
	debug(ALL(num2));
	for(auto i:divs){
		for(auto val:num2){
			if(i%val==0){
				dump((p-1)/i);
				res+=phi((p-1)/i);
				break;
			}
		}
	}

	cout<<res<<endl;

	return 0;
}