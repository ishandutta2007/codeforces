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
int n;
int a[100005];
lint sum[100005];
lint ans1;
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	REP(i,n) sum[i+1]=sum[i]+a[i];
	REP(i,n) ans1+=a[i]*(lint)(n-1-i);
	int q;cin>>q;
	REP(hoge,q){
		int k;cin>>k;
		if(k==1){
			cout<<ans1<<endl;
		}else{
			lint res=0;
			lint num=k,pos=n-2;
			while(pos>=0){
				res+=sum[pos+1];
				pos-=num;
				num*=k;
			}
			cout<<res<<endl;
		}
	}
					



	return 0;
}