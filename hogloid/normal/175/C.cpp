#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
typedef pair<int,int> pi;
int n;
pair<int,lint> fig[105];
lint setup[105];
int main(){
	scanf("%d",&n);
	REP(i,n) cin>>fig[i].sc>>fig[i].fr;
	sort(fig,fig+n);
	int t;scanf("%d",&t);
	REP(i,t) cin>>setup[i];
	setup[t]=1e15;
	int ind=0;
	lint rest=setup[0];
	lint res=0;
	REP(i,n){
		if(rest>=fig[i].sc){
			rest-=fig[i].sc;
			res+=fig[i].sc*(lint)(ind+1)*fig[i].fr;
		}else{
			res+=rest*(lint)(ind+1)*fig[i].fr;
			fig[i].sc-=rest;
			++ind;
			rest=(setup[ind]-setup[ind-1]);
			--i;
		}
	}
	cout<<res<<endl;
	return 0;
}