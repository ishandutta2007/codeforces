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
lint luck[100005];
int cnt=0;
lint n,k;
lint fact[20];
int used[20];
bool isLucky(lint a){
	int res=1;
	while(a>0){
		if(a%10!=4 && a%10!=7) res=0;
		a/=10;
	}
	return res;
}
int main(){
	fact[0]=1;
	REP(i,19) fact[i+1]=fact[i]*(i+1);
	for(int i=1;i<=10;++i){
		REP(j,1<<i){
			lint num=0;
			REP(k,i) num=num*10+(j>>k&1?7:4);
			--num;
			luck[cnt++]=num;
		}
	}
	sort(luck,luck+cnt);

	cin>>n>>k;
	--k;

	int res=0;
	
	int end=n-1-13;//...end]
	vector<int> srch;
	REP(i,cnt){
		if(luck[i]<=end){
			++res;
		}else if(luck[i]>=n) break;
		else {
			srch.pb(luck[i]);
		}
	}

	vector<lint> perm;
	int size=min(13ll,n);
	//search k-th permutation of size min(13,n)
	
	REP(i,size){
		int seek=0;
		while(seek<size && used[seek]) ++seek;

		while(k>=fact[size-1-i]){
			k-=fact[size-1-i];
			++seek;
			while(seek<size && used[seek]) ++seek;
			if(seek==size){
				puts("-1");
				return 0;
			}
		}
		used[seek]=1;
		perm.pb(seek);
	}

	if(end<0){
		REP(i,srch.size()) if(isLucky(perm[srch[i]]+1)) ++res;
	}else{
		REP(i,srch.size()){
			if(isLucky(perm[srch[i]-end-1]+1+end+1)) ++res;
		}
	}

	cout<<res<<endl;
	return 0;
}