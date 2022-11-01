#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
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
pi p[200005];

int expo[200005];
set<int> used;
void doit(int len,int add){
	REPN(k,len+1,1){
		
		int tmp=k;
		for(int i2=2;i2*i2<=tmp;++i2){
			while(tmp%i2==0){
				tmp/=i2;
				used.insert(i2);
				expo[i2]+=add;
			}
		}
		if(tmp>1) expo[tmp]+=add,used.insert(tmp);

	}
}
lint m;
lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%m;
		a=a*a%m;
		k>>=1;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	REP(i,n*2){
		int a;scanf("%d",&a);
		p[i]=mp(a,i%n);
	}
	n*=2;
	sort(p,p+n);
	
	cin>>m;
	
	lint res=1;
	REP(i,n){
		used.clear();
		int j=i;
		while(j<n && p[j].fr==p[i].fr){
			int j2=j;
			while(j2<n && p[j2]==p[j]) ++j2;

			doit(j2-j,-1);
			j=j2;
		}
		
		int len=j-i;

		doit(len,1);

		set<int>::iterator it=used.begin();

		lint tmp=1;
		while(it!=used.end()){
			int a=*it;
			tmp=tmp*mpow(a,expo[a])%m;
			expo[a]=0;
			++it;
		}
		i=j-1;
		res=res*tmp%m;
	}
	cout<<res<<endl;
	return 0;
}