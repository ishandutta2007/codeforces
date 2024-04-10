#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
char seq[1005],seq2[1005];
int code[250];
int m,k;
pi f(int n){
	pi res=mp(0,0);
	REP(i,n){
		if((seq[i%m]+1)%3==seq2[i%k]) ++res.fr;
		else if(seq[i%m]==(seq2[i%k]+1)%3) ++res.sc;
	}
	return res;
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s%s",seq,seq2);
	m=strlen(seq);k=strlen(seq2);
	code['R']=0;code['P']=1;code['S']=2;
	REP(i,m) seq[i]=code[seq[i]];
	REP(i,k) seq2[i]=code[seq2[i]];
	int lcm=m*k/__gcd(m,k);
	if(n<lcm){
		pi res=f(n);
		printf("%d %d\n",res.fr,res.sc);
	}else{
		pi add=f(n%lcm),loop=f(lcm);
		loop.fr*=n/lcm;loop.sc*=n/lcm;
		loop.fr+=add.fr;loop.sc+=add.sc;
		printf("%d %d\n",loop.fr,loop.sc);
	}
	return 0;
}