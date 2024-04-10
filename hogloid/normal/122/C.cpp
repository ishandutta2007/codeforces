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
lint l,r;
lint luck[100005];
int cnt=0;
lint solve(lint end){
	lint res=0;
	REPN(i,cnt,1){
		if(end<=luck[i]){
			res+=luck[i]*(end-luck[i-1]);
			break;
		}else res+=luck[i]*(luck[i]-luck[i-1]);
	}
	return res;
}
int main(){
	cin>>l>>r;
	
	for(int i=1;i<=10;++i){
		REP(j,1<<i){
			lint num=0;
			REP(k,i) num=num*10+(j>>k&1?7:4);
			luck[cnt++]=num;
		}
	}
	luck[cnt++]=0;
	sort(luck,luck+cnt);

	cout<<solve(r)-solve(l-1)<<endl;
	return 0;
}