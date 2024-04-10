#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<map>
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
typedef unsigned long long int lint;
typedef pair<int,int> pi;
int n;
int ar[100005];
vector<int> luck;
bool isluck(int a){
	while(a>0){
		if(a%10!=4 && a%10!=7) return false;
		a/=10;
	}
	return true;
}

int nxt[100005];
map<int,int> prev;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);
	
	REP(i,n) if(isluck(ar[i])) luck.pb(i);

	if(!luck.empty()) for(int i=luck.size()-1;i>=0;--i){
		if(prev.count(ar[luck[i]])==0) nxt[luck[i]]=INF;
		else nxt[luck[i]]=prev[ar[luck[i]]];
		prev[ar[luck[i]]]=luck[i];
	}

	lint res=(n+2)*(lint)(n+1)/2*n/3*(n-1)/4;

	
	if(!luck.empty()) REP(i,luck.size()-1){
		int p=luck[i];
		set<int> divs;
		divs.insert(luck[i]);divs.insert(n);
		int spc=luck[i+1]-luck[i];
		lint tmp=0;
		for(int j=i;j>=0;--j) if(nxt[luck[j]]>p){
			for(int k=nxt[luck[j]];k<INF;k=nxt[k]){
				set<int>::iterator it=divs.insert(k).fr,prev,nxt;
				prev=nxt=it;
				--prev;
				++nxt;

				if(prev==divs.begin()) tmp+=spc*(lint)(k-*prev + k-*prev -spc+1)/2*
						(luck[j]+1)*(*nxt-k);
				else tmp+=spc*(lint)(*nxt-k)*(luck[j]+1)*(k-*prev);
			}
		}
		res-=tmp;
	}

	cout<<res<<endl;

	return 0;
}