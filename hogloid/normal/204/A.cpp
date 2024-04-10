#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
lint powe10[20];
lint get(lint a){//...a]
	if(a<10) return a;
	string s;
	stringstream ss;ss<<a;
	s=ss.str();
	
	lint res=0;
	for(int i=1;i<s.size();++i){
		if(i==1) res+=9;
		else res+=9*powe10[i-2];
	}
	lint rest=a-powe10[s.size()-1];
	lint block=powe10[s.size()-1]+1;
	if(rest==0) return res;
	--rest;
	++res;
	res+=rest/block*powe10[s.size()-2];
	rest%=block;
	if(rest+1==block) --res;
	res+=rest/10;
	return res;
}
int main(){
	powe10[0]=1;
	REP(i,19) powe10[i+1]=powe10[i]*10;
	lint l,r;cin>>l>>r;
	cout<<get(r)-get(l-1)<<endl;
	return 0;
}