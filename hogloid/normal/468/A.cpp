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
int main(){
	cin>>n;
	if(n<=3) puts("NO");
	else{
		puts("YES");
		if(n%4==0){
			puts("1 * 2 = 2");
			puts("2 * 3 = 6");
			puts("6 * 4 = 24");
		}
		if(n%4==1){
			puts("3 * 5 = 15");
			puts("2 * 4 = 8");
			puts("15 + 8 = 23");
			puts("23 + 1 = 24");
		}
		if(n%4==2){
			puts("4 * 6 = 24");
			puts("24 + 5 = 29");
			puts("2 * 3 = 6");
			puts("29 - 6 = 23");
			puts("23 + 1 = 24");
		}
		if(n%4==3){
			puts("4 * 6 = 24");
			puts("2 * 5 = 10");
			puts("1 * 3 = 3");
			puts("24 + 10 = 34");
			puts("34 - 7 = 27");
			puts("27 - 3 = 24");
		}
		for(int st=n%4+4+1;st<n;st+=4){
			printf("24 + %d = %d\n",st,24+st);
			printf("%d - %d = %d\n",24+st,(st+1),24-1);
			printf("%d - %d = %d\n",24-1,(st+2),24-st-3);
			printf("%d + %d = %d\n",24-st-3,st+3,24);
		}
	}

	return 0;
}