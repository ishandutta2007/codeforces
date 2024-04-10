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
typedef pair<lint,lint> pi;

int n;
lint a[100005],b[100005];

pi stk[100005];
int m;

double getsect(pi& a,pi& b){//a.fr>b.fr;
	return (b.sc-a.sc)/(double)(a.fr-b.fr);
}
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];
	
	
	int st=0,en=0;
	stk[en++]=mp(b[0],0);
		
	
	lint ans;
	for(int i=1;i<n;++i){
		while(st+1<en && getsect(stk[st],stk[st+1])<a[i]) ++st;

		pi top=stk[st];
		lint reach=top.fr*a[i]+top.sc;
		ans=reach;
		
		pi ins=mp(b[i],reach);
		while(st<en-1){
			double L=getsect(stk[en-2],stk[en-1]),R=getsect(stk[en-1],ins);
			if(R<=L) --en;
			else break;
		}
		stk[en++]=ins;
	}

	cout<<ans<<endl;



	return 0;
}