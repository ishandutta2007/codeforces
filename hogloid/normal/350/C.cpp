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
int sign(int a){
	if(a>0) return 2;
	if(a==0) return 1;
	return 0;
}

char Xtype[]={'L',' ','R'};
char Ytype[]={'D',' ','U'};

pi ps[100005];
bool cmp(const pi& a,const pi& b){
	if(abs(a.fr)!=abs(b.fr)) return abs(a.fr)<abs(b.fr);
	return abs(a.sc)<abs(b.sc);
}

int main(){
	cin>>n;
	int res=0;
	REP(i,n){
		int x,y;cin>>x>>y;
		ps[i]=mp(x,y);
		if(x) res+=2;
		if(y) res+=2;
		res+=2;
	}
	cout<<res<<endl;
	sort(ps,ps+n,cmp);
	REP(i,n){
		int x=ps[i].fr,y=ps[i].sc;
		char c=Xtype[sign(x)];
		if(x) printf("%d %d %c\n",1,abs(x),c);
		c=Ytype[sign(y)];
		if(y) printf("%d %d %c\n",1,abs(y),c);
		puts("2");
		c=Xtype[sign(-x)];
		if(x) printf("%d %d %c\n",1,abs(x),c);
		c=Ytype[sign(-y)];
		if(y) printf("%d %d %c\n",1,abs(y),c);
		puts("3");
	}


	return 0;
}