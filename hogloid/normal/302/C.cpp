#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int ar[205];



int main(){
	cin>>n;
	REP(i,n*2-1) cin>>ar[i];
	int tot=0,zero=0;
	REP(i,n*2-1){
		tot+=abs(ar[i]);
		if(ar[i]==0) zero=1;
	}
	if(n&1 || zero){
		cout<<tot<<endl;
	}else{
		vector<int> posi,nega;
		REP(i,n*2-1){
			if(ar[i]<0) nega.pb(-ar[i]);
			if(ar[i]>0) posi.pb(ar[i]);
		}
		sort(ALL(nega),greater<int>());
		sort(ALL(posi),greater<int>());
		int res=0;

		if(nega.size()%2==0){
			res=tot;
		}else{
			int resA=tot,resB=tot;
			if(nega.empty()) res=tot-posi.back()*2;
			else if(posi.empty()) res=tot-nega.back()*2;
			else res=max(tot-posi.back()*2,tot-nega.back()*2);
		}
		cout<<res<<endl;
	}
	return 0;
}