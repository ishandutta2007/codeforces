#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<fstream>
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
int m,k,n;
int like[105];
pi data[105];
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	cin>>m>>k;
	REP(i,k){
		int a;cin>>a;
		--a;
		like[a]=1;
	}
	cin>>n;
	char hogehoge[20];

	REP(i,n){
		cin>>hogehoge;
		int d;cin>>d;

		int blank=0,value=0,unlike=0;
		REP(j,d){
			int b;cin>>b;
			--b;
			if(b==-1) ++blank;
			else if(like[b]) ++value;
			else ++unlike;
		}
		int rest=k-value,rest2=(m-k)-unlike;
		
		
		data[i]=mp(value+min(rest,blank),value+blank-min(blank,rest2));

	}
	REP(i,n){

		int max_least=-1,max_maxim=-1;
		REP(j,n) if(i!=j){
			max_least=max(max_least,data[j].sc);
			max_maxim=max(max_maxim,data[j].fr);
		}
		int res;
		if(data[i].sc>=max_maxim) res=0;
		else if(data[i].fr<max_least) res=1;
		else res=2;
		cout<<res<<endl;
	}
	
	return 0;
}