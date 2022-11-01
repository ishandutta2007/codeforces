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
pi p[10];
pi decr(pi a,pi b){//a-b
	return mp(a.fr-b.fr,a.sc-b.sc);
}
int dot(pi a,pi b){
	return a.fr*b.fr+a.sc*b.sc;
}
int len(pi a,pi b){
	pi d=decr(a,b);
	return d.fr*d.fr+d.sc*d.sc;
}

bool isrect(pi* a){
	sort(a,a+4);
	do{
		if(len(a[0],a[1])>0 && len(a[1],a[2])>0 && 
			dot(decr(a[1],a[0]),decr(a[3],a[0]))==0 &&
			dot(decr(a[2],a[1]),decr(a[0],a[1]))==0 &&
			dot(decr(a[3],a[2]),decr(a[1],a[2]))==0) return true;
	}while(next_permutation(a,a+4));
	return false;
}
bool issqar(pi* a){
	sort(a,a+4);
	do{
		if(len(a[0],a[1])==len(a[1],a[2]) && len(a[1],a[2])==len(a[2],a[3]) &&
			len(a[2],a[3])==len(a[3],a[0]) && 
			dot(decr(a[1],a[0]),decr(a[3],a[0]))==0 &&
			dot(decr(a[2],a[1]),decr(a[0],a[1]))==0 &&
			dot(decr(a[3],a[2]),decr(a[1],a[2]))==0) return true;
	}while(next_permutation(a,a+4));
	return false;
}

int main(){
	REP(i,8) cin>>p[i].fr>>p[i].sc;

	REP(i,1<<8) if(__builtin_popcount(i)==4){
		pi a[4],b[4];
		int n=0,m=0;
		REP(j,8){
			if(i>>j&1) a[n++]=p[j];
			else b[m++]=p[j];
		}
		if(isrect(a) && issqar(b)){
			puts("YES");
			REP(j,8) if(!(i>>j&1)) printf("%d ",j+1);
			putchar('\n');
			REP(j,8) if(i>>j&1) printf("%d ",j+1);
			putchar('\n');
			return 0;
		}
	}
	puts("NO");

	return 0;
}