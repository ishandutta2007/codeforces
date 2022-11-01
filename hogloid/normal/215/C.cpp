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
int n,m,s;
int check(int w,int h,int w2,int h2){
	if(!(w2&1)) return 0;
	w=w*2+1;h=h*2+1+h2*2;
	if(w<=w2) return 0;
	return max(n+1-w,0)*max(m+1-h,0);
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	lint res=0,res2=0;
	REP(i,(n+1)/2) REP(j,(m+1)/2){
		if((i*2+1)*(j*2+1)>s) break;
		int rest=s-(i*2+1)*(j*2+1);
		if(rest==0){
			lint tmp=(i+1)*(j+1)-1;
			tmp*=max(n+1-i*2-1,0)*max(m+1-j*2-1,0);
			res+=tmp;
			res2+=max(n+1-i*2-1,0)*max(m+1-j*2-1,0);
		}else if(rest%2==0){
			rest/=2;
			for(int k=1;k*k<=rest;++k) if(rest%k==0){
				res+=check(i,j,k,rest/k);
				if(k*k!=rest) res+=check(i,j,rest/k,k);
			}
		}
	}
	cout<<res*2+res2<<endl;
				
	return 0;
}