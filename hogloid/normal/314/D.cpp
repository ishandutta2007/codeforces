#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<complex>
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
typedef complex<double> P;
int n;
P ps[100005];
bool cmp(const P& a,const P& b){
	if(abs(a.real()-b.real())<1e-9) return a.imag()<b.imag();
	return a.real()<b.real();
}

const double PI=acos(-1.0);

double evermin[100005],evermax[100005],latermin[100005],latermax[100005];
int main(){
	scanf("%d",&n);
	REP(i,n){
		int a,b;scanf("%d%d",&a,&b);
		ps[i]=P((double)a,(double)b);
		ps[i]*=polar(1.0,PI/4);
	}

	sort(ps,ps+n,cmp);
	
	evermin[0]=1e15;
	evermax[0]=-1e15;
	latermin[n]=1e15;
	latermax[n]=-1e15;

	REP(i,n){
		evermin[i+1]=min(evermin[i],ps[i].imag());
		evermax[i+1]=max(evermax[i],ps[i].imag());
	}
	for(int i=n-1;i>=0;--i){
		latermin[i]=min(latermin[i+1],ps[i].imag());
		latermax[i]=max(latermax[i+1],ps[i].imag());
	}
	
	double lb=0,ub=1e10;
	REP(hoge,65){
		double md=(lb+ub)/2;
		
		int j=0,ok=0;
		REP(i,n){
			while(j<n && ps[j].real()-ps[i].real()<=md*2) ++j;

			double maxi=max(evermax[i],latermax[j]),
				mini=min(evermin[i],latermin[j]);

			if(maxi-mini<=2*md){
				ok=true;
				break;
			}
		}
		if(ok) ub=md;
		else lb=md;
	}
	printf("%.10f\n",lb*sqrt(2.0));

	return 0;
}