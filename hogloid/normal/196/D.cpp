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
int d,n;
char s[400005];
lint ppow[400005];
lint hash1[400005],hash2[400005];
lint B=100000007;
bool check(int l,int r){
	if(l<0) return false;
	int len=r-l;
	if(len&1){
		int md=l+len/2;
		if((hash1[md]-hash1[l]*ppow[md-l])*ppow[md+1]==hash2[r]-hash2[md+1]) return true;
	}else{
		int md=l+len/2;
		if((hash1[md]-hash1[l]*ppow[md-l])*ppow[md]==hash2[r]-hash2[md]) return true;
	}
	return false;
}
bool dfs(int ind,bool flag){
	if(ind==n) return true;
	char prev=s[ind];
	for(char c=(flag?'a':s[ind]);c<='z';++c){
		if(flag==false && ind==n-1 && c==s[ind]) continue;
		hash1[ind+1]=hash1[ind]*B+c;
		hash2[ind+1]=hash2[ind]+c*ppow[ind];
		s[ind]=c;
		if(!check(ind-d+1,ind+1) && !check(ind-d,ind+1) && dfs(ind+1,(flag || c!=prev))) return true;
	}
	return false;
}
int main(){
	ppow[0]=1;
	REP(i,400000) ppow[i+1]=ppow[i]*B;
	cin>>d>>s;
	n=strlen(s);

	if(dfs(0,false)) printf("%s\n",s);
	else puts("Impossible");
	return 0;
}