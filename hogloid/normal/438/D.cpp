#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).beginn(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m;
int ar[100005];

int B=300;
set<pi> s[1005];
lint sum[1005];

int beginn[1005],last[1005];

pi ins[1005];
int main(){
	cin>>n>>m;
	REP(i,n) scanf("%d",&ar[i]);
	
	int k=(n-1)/B+1;
	REP(i,1005) beginn[i]=INF;
	REP(i,n){
		s[i/B].insert(mp(ar[i],i));
		sum[i/B]+=ar[i];

		chmin(beginn[i/B],i);
		chmax(last[i/B],i);
	}
	REP(i,k) ++last[i];

	REP(hoge,m){
		int t;scanf("%d",&t);
		if(t==1){
			int l,r;scanf("%d%d",&l,&r);--l;
			
			lint res=0;
			for(;l%B>0 && l<r;++l) res+=ar[l];
			
			for(;r%B>0 && l<r;--r) res+=ar[r-1];
			if(l<r){
				REP(i,k) if(l<=beginn[i] && last[i]<=r) res+=sum[i];
			}
			cout<<res<<'\n';
		}else if(t==2){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);--l;

			for(;l%B>0 && l<r;++l) if(ar[l]>=x){
				int b=l/B;
				s[b].erase(mp(ar[l],l));
				sum[b]-=ar[l];

				ar[l]%=x;

				sum[b]+=ar[l];
				s[b].insert(mp(ar[l],l));
			}
			for(;r%B>0 && l<r;--r) if(ar[r-1]>=x){
				int b=(r-1)/B;
				s[b].erase(mp(ar[r-1],r-1));
				sum[b]-=ar[r-1];
				
				ar[r-1]%=x;

				sum[b]+=ar[r-1];
				s[b].insert(mp(ar[r-1],r-1));
			}
			if(l<r){
				REP(i,k) if(l<=beginn[i] && last[i]<=r){

					auto it=s[i].end();
					int cnt=0;
					--it;
					while(1){
						if(it->fr>=x){
							sum[i]-=it->fr;
							ins[cnt++]=mp(it->fr%x,it->sc);
							ar[it->sc]=it->fr%x;
							
							if(it==s[i].begin()){
								s[i].erase(it);break;
							}

							s[i].erase(it--);
						}else break;
					}
					REP(hoge2,cnt) s[i].insert(ins[hoge2]),
						sum[i]+=ins[hoge2].fr;
				}
			}
		}else{
			int k,x;scanf("%d%d",&k,&x);--k;
			int b=k/B;
			sum[b]-=ar[k];
			s[b].erase(mp(ar[k],k));

			ar[k]=x;
			sum[b]+=ar[k];
			s[b].insert(mp(ar[k],k));
		}
	}
	return 0;
}