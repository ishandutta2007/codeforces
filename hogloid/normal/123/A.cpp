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
string s;
struct uf{
	int par[1005],size[1005];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,1005) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
		size[b]+=size[a];
	}
};
uf u;
bool isprime(int a){
	for(int i=2;i*i<=a;++i) if(a%i==0) return false;
	return true;
}

int main(){
	int count[30]={0};
	cin>>s;
	int n=s.size();
	REP(i,n) count[s[i]-'a']++;
		
	for(int i=2;i<=n;++i) if(isprime(i)){
		for(int j=i;j<=n;j+=i) u.unite(j-1,i-1);
	}

	int largest=*max_element(count,count+26),which=max_element(count,count+26)-count;

	int one=0,other=-1,otherw=-1;
	REP(i,n) if(u.root(i)==i){
		if(u.size[i]==1) ++one;
		else other=u.size[i],otherw=i;
	}
	if(other<=largest){
		puts("YES");
		if(other>=0) count[which]-=other;
		REP(i,n){
			if(u.root(i)==otherw) putchar('a'+which);
			else{
				REP(j,26) if(count[j]>0){
					--count[j];
					putchar('a'+j);
					break;
				}
			}
		}
		putchar('\n');
	}else puts("NO");

	return 0;
}