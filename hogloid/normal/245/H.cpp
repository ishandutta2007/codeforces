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
char s[5005];
int q,n;
pair<pi,int> query[1000005];
static const int MAX_N=5005;
struct BIT{
	int val[MAX_N*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};
BIT bit;
pi event[13000000];
lint hash[5005],rev[5005];
lint B=100000007;
lint powerB[5005];
int ans[1000005];
int main(){
	powerB[0]=1;
	REP(i,5000) powerB[i+1]=powerB[i]*B;
	scanf("%s",s);
	n=strlen(s);
	cin>>q;
	REP(i,q){
		scanf("%d%d",&query[i].fr.fr,&query[i].fr.sc),query[i].sc=i;
		--query[i].fr.fr;
	}
	sort(query,query+q);

	bit.init(5005);

	hash[0]=0;
	REP(i,n){
		hash[i+1]=hash[i]*B+s[i];
	}
	rev[n]=0;
	for(int i=n-1;i>=0;--i){
		rev[i]=rev[i+1]*B+s[i];
	}
	int m=0;
	REP(i,n) REPN(j,n,i){//[i,j]
		int len=j-i+1;
		int piv=(j+i+1)/2;
		if(len&1){
			if(hash[piv]-hash[i]*powerB[piv-i]==rev[piv+1]-rev[j+1]*powerB[j-piv]){
				event[m++]=mp(i,j);
			}
		}else{
			if(hash[piv]-hash[i]*powerB[piv-i]==rev[piv]-rev[j+1]*powerB[j+1-piv]){
				event[m++]=mp(i,j);
			}
		}
	}
	sort(event,event+m);
	REP(i,m){
		bit.add(event[i].sc,1);
	}
	int j=0;
	REP(i,q){
		pair<pi,int>& q=query[i];
		while(j<=m && event[j].fr<q.fr.fr){
			bit.add(event[j].sc,-1);
			++j;
		}
		ans[q.sc]=bit.query(q.fr.sc);
	}
	REP(i,q) printf("%d\n",ans[i]);



	return 0;
}