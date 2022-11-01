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
int n,m;
pair<pi,pi> wood[100005];
pi mush[10005];
struct segtree{
	double val[1600000];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=1;
	}
	void mul(int a,int b,int i,int l,int r,double v){
		if(a<=l && r<=b){
			val[i]*=v;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		mul(a,b,i*2+1,l,md,v);
		mul(a,b,i*2+2,md,r,v);
	}
	double query(int k){
		k+=n-1;
		double res=val[k];
		while(k>0){
			k=(k-1)/2;
			res*=val[k];
		}
		return res;
	}
};
segtree seg;
int zip[400005],zn;
long double tomul[400005],sum[400005];
int zero[400005],zerosum[400005];
int main(){
	cin>>n>>m;
	REP(i,n){
		scanf("%d%d%d%d",&wood[i].fr.fr,&wood[i].fr.sc,&wood[i].sc.fr,&wood[i].sc.sc);
		zip[zn++]=wood[i].fr.fr;
		zip[zn++]=wood[i].fr.fr+wood[i].fr.sc;
		zip[zn++]=wood[i].fr.fr-wood[i].fr.sc;
	}
	REP(i,m){
		scanf("%d%d",&mush[i].fr,&mush[i].sc);
		zip[zn++]=mush[i].fr;
	}
	sort(zip,zip+zn);
	zn=unique(zip,zip+zn)-zip;

	seg.init(zn);
	
	sort(wood,wood+n);
	sort(mush,mush+m);
	REP(i,zn+1) tomul[i]=1;
	REP(i,n){
		int p=lower_bound(zip,zip+zn,wood[i].fr.fr)-zip,
			begin=lower_bound(zip,zip+zn,wood[i].fr.fr-wood[i].fr.sc)-zip,
			end=lower_bound(zip,zip+zn,wood[i].fr.fr+wood[i].fr.sc)-zip;
		if(wood[i].sc.fr==100){
			++zero[begin];
			--zero[p];
		}else{
			seg.mul(begin,p,0,0,seg.n,(100-wood[i].sc.fr)/100.0);
		}

		if(wood[i].sc.sc==100){
			++zero[p+1];
			--zero[end+1];
		}else{
			seg.mul(p+1,end+1,0,0,seg.n,(100-wood[i].sc.sc)/100.0);
		}
	}
	zerosum[0]=zero[0];
	REP(i,zn){
		zerosum[i+1]=zerosum[i]+zero[i+1];
	}
	double res=0;
	REP(i,m){
		int p=lower_bound(zip,zip+zn,mush[i].fr)-zip;
		if(zerosum[p]) continue;
		res+=mush[i].sc*seg.query(p);
	}
	printf("%.10f\n",res);



	return 0;
}