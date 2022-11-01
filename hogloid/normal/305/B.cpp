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
lint p,q;
int n;
lint a[100],b[100];
int main(){
	cin>>p>>q>>n;
	REP(i,n) cin>>a[i];
	
	if(n>1 && a[n-1]==1){
		++a[n-2];
		--n;
	}


	lint g=__gcd(p,q);
	p/=g;
	q/=g;
	
	int cnt=0;
	while(q){
		lint z=p/q,rema=p%q;
		b[cnt++]=z;
		lint nxtp=q,nxtq=rema;

		p=nxtp;
		q=nxtq;
	}

	int fail=(n!=cnt);
	REP(i,n) if(a[i]!=b[i]) fail=1;

	if(fail) puts("NO");
	else puts("YES");


	return 0;
}