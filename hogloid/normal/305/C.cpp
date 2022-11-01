#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
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
typedef long long int lint;
typedef pair<int,int> pi;
int n;
map<int,int> bits;
vector<int> bits2;
int main(){
	cin>>n;
	REP(i,n){
		int a;scanf("%d",&a);
		++bits[a];
	}

	while(!bits.empty()){
		pi t=*bits.begin();
		bits.erase(bits.begin());
		if(t.sc){
			if(t.sc&1) bits2.pb(t.fr);
			bits[t.fr+1]+=t.sc/2;
		}
	}

	int largest=bits2.back();
	dump(largest);
	int res=largest-bits2.size()+1;
	printf("%d\n",res);
	return 0;
}