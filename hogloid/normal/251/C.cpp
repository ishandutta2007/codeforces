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
lint a,b;
int k;
lint solve(lint a,lint b,int k){
	int res=0;
	while(b>a){
		lint mini=b-1;
		for(int i=2;i<=k;++i) if(b-b%i>=a){
			mini=min(mini,b-b%i);
		}
		b=mini;
		++res;
	}
	return res;
}

lint B=360360;
int main(){
	cin>>b>>a>>k;
	lint C=solve(0,B,k),res=0;
	if(a%B<=b%B){
		lint mul=b/B-a/B;
		b%=B;
		a%=B;
		res=mul*C+solve(a,b,k);
	}else{
		lint mul=b/B-a/B-1;
		b%=B;
		a%=B;
		b+=B;
		res=mul*C+solve(a,b,k);
	}
	cout<<res<<endl;
	return 0;
}