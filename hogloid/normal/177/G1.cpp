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
lint k;
int m;
static const int MF=31;
string fib[MF+5];
int table[100005];
int calc(string& key,string& s){
	if(s.size()<key.size()) return 0;
	int n=key.size();
	table[0]=-1;
	key+='$';
	for(int i=1;i<=n;++i){
		int j=table[i-1];
		while(j>=0 && key[j+1]!=key[i]) j=table[j];
		if(key[j+1]==key[i]) ++j;
		table[i]=j;
	}

	int j=-1;
	int res=0;
	REP(i,s.size()){
		while(j>=0 && key[j+1]!=s[i]) j=table[j];
		if(key[j+1]==s[i]) ++j;
		if(j==n-1) ++res;
	}
	key.resize(key.size()-1);
	return res;
}

lint BASE[4][4]={
	{1,1,1,0},
	{1,2,1,1},
	{0,0,1,0},
	{0,0,0,1}
};
typedef lint item ;//use as :typedef lint item;
typedef vector<item> vec;
typedef vector<vector<item> > mat;
const lint mod=1000000007;
mat matpow(const mat& a,const mat& b){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) REP(j,n) REP(k,n){
		res[i][j]+=a[i][k]*b[k][j];
		res[i][j]%=mod;
	}
	return res;
}
mat mpow(mat& a,lint k){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) res[i][i]=1;
	while(k){
		if(k&1) res=matpow(res,a);
		a=matpow(a,a);
		k>>=1;
	}
	return res;
}

lint solve(string& s){

	int ind=0;
	while(fib[ind].size()<=s.size()) ++ind;
	if(ind>k) return calc(s,fib[k]);
	string& q=fib[ind],q2=fib[ind+1],q3=fib[ind+2];
	int a=calc(s,q),b=calc(s,q2),c=calc(s,q3),d=calc(s,fib[ind+3]);
	
	int addA=c-a-b,addB=d-b-c;

	lint rest=k-ind;
	lint odd=(rest&1);
	rest=rest/2;

	mat M(4,vec(4));
	REP(i,4) REP(j,4) M[i][j]=BASE[i][j];

	mat M2=mpow(M,rest);
	vec init(4);
	init[0]=a;init[1]=b;init[2]=addA;init[3]=addB;
	lint res=0;
	if(odd){
		REP(i,4) res+=M2[1][i]*init[i]%mod;
		res%=mod;
	}else{
		REP(i,4) res+=M2[0][i]*init[i]%mod;
		res%=mod;
	}
	return res;
}
int main(){
	fib[1]="a";fib[2]="b";
	for(int i=3;i<MF;++i) fib[i]=fib[i-1]+fib[i-2];
	
	cin>>k>>m;
	string s;
	REP(hoge,m){
		cin>>s;
		solve(s);
		cout<<solve(s)<<endl;
	}

	return 0;
}