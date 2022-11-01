
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
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

int n;
int isprm(int a){
	if(a==1) return false;
	for(int j=2;j*j<=a;++j) if(a%j==0) return false;
	return true;
}
	

pi res[100005];
int rcnt;
int used[100005];

int ar[100005],cnt;
int main(){
	
	cin>>n;
	
	for(int i=n;i>=2;--i) if(isprm(i)){
		
		cnt=0;
		for(int j=i;j<=n;j+=i) if(!used[j] && j!=i*2){
			ar[cnt++]=j;
		}
		if(i*2<=n && used[i*2]){
			dump("HOGE");
		}
		if(i*2<=n) ar[cnt++]=i*2;
		REP(j,cnt/2){
			res[rcnt++]=mp(ar[j*2],ar[j*2+1]);
			used[ar[j*2]]=used[ar[j*2+1]]=1;
		}
	}

	printf("%d\n",rcnt);
	REP(i,rcnt){
		printf("%d %d\n",res[i].fr,res[i].sc);
	}



	
	return 0;
}