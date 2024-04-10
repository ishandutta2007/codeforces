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
lint gcd(lint a,lint b){
	if(a<b) swap(a,b);
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}

int main(){
	lint n;cin>>n;
	if(n<=200){
		lint maxi=0;
		int tmp;
		REPN(i,n+1,1) REPN(j,n+1,i) REPN(k,n+1,j){
			tmp=i*j/__gcd(i,j);
			tmp=tmp*k/__gcd(tmp,k);
			maxi=max(maxi,(lint)tmp);
		}
		cout<<maxi<<endl;
		return 0;
	}
	lint res=0;
	for(lint i=n;i>=1;--i) for(lint j=i;j>=1;--j) if(gcd(i,j)==1){
		if(res>=i*j*j) break;
		for(lint k=j;k>=1;--k){
			if(res>=k*j*i) break;
			if(gcd(i,k)==1 && gcd(j,k)==1){
				res=max(res,i*j*k);
			}
		}
	}
	cout<<res<<endl;
		
	return 0;
}