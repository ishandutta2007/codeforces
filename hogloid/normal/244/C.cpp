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
int a[100005];
int nxt[20][100005];

pi pos[25];
int all[2200000];
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,20) nxt[i][n]=INF;
	for(int i=n-1;i>=0;--i){
		REP(j,20){
			nxt[j][i]=nxt[j][i+1];
			if(a[i]>>j&1) nxt[j][i]=i;
		}
	}
	lint res=0;
	int k=0;
	REP(i,n){
		int m=0;
		REP(j,20) pos[m++]=mp(nxt[j][i],j);
		pos[m++]=mp(i,-1);
		sort(pos,pos+m);

		int sum=0;
		REP(j,m) if(pos[j].fr<INF){
			int l=j;
			while(l<m && pos[l].fr==pos[j].fr){
				if(pos[l].sc>=0) sum|=(1<<pos[l].sc);
				++l;
			}
			all[k++]=sum;
		}
	}
	sort(all,all+k);
	k=unique(all,all+k)-all;
	cout<<k<<endl;

	return 0;
}