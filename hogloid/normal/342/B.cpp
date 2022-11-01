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
int n,m,s,f;
pair<int,pi> watch[100005];
int main(){
	cin>>n>>m>>s>>f;
	--s;--f;
	REP(i,m){
		int t,l,r;cin>>t>>l>>r;--l;
		watch[i]=mp(t,mp(l,r));
	}
	watch[m]=mp(INF,mp(-1,-1));

	int i=0;
	for(int t=1;s!=f;++t){
		pair<int,pi>& w=watch[i];
		int dst;
		if(s<f) dst=s+1;
		else dst=s-1;
		if(w.fr==t && ((w.sc.fr<=s && s<w.sc.sc) ||
				(w.sc.fr<=dst && dst<w.sc.sc))){
		if(w.fr==t) ++i;
			putchar('X');continue;
		}
		if(w.fr==t) ++i;
		if(s<f) putchar('R');
		else putchar('L');
		s=dst;

	}
	putchar('\n');


	return 0;
}