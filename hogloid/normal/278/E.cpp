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
int n,m,k;
pair<int,pi> hor[100005],vert[100005];
int xzip[200005],xn,yzip[200005],yn;
int m1,m2;

int last=0,sum=0;
pair<pi,pi> doit(){
	
	last=0;
	int largest=0;
	REP(i,31) if(sum>>i&1) largest=(1<<i);
	REP(i,m2){
		int j=i;
		if((vert[i].fr-last-1)>0 && (m&largest)) return mp(mp(last+1,0),mp(last+1,m-(m^sum)));
		last=vert[i].fr;
		int maxreach=0,sumlen=0,tmp=largest;
		while(j<m2 && vert[j].fr==vert[i].fr){
			if(maxreach<vert[j].sc.fr){
				sumlen+=(vert[j].sc.fr-maxreach);
			}
			maxreach=max(maxreach,vert[j].sc.sc);
			++j;
		}
		sumlen+=(m-maxreach);
		if(sumlen&largest){
			int want=sumlen^sum;
			maxreach=0;
			if(want==0) return mp(mp(last,0),mp(last,m));
			j=i;
			while(j<m2 && vert[j].fr==vert[i].fr){
				if(maxreach<vert[j].sc.fr){
					want-=(vert[j].sc.fr-maxreach);
					if(want<=0) return mp(mp(last,vert[j].sc.fr+want),mp(last,m));
				}
				maxreach=max(maxreach,vert[j].sc.sc);
				++j;
			}
			want-=(m-maxreach);
			if(want<=0) return mp(mp(last,m+want),mp(last,m));
		}
		i=j-1;
	}
	if((n-last-1)>0 && (m&largest)) return mp(mp(last+1,0),mp(last+1,m-(m^sum)));
	prl;
	last=0;
	REP(i,m1){
		int j=i;
		if((hor[i].fr-last-1)>0 && (n&largest)) return mp(mp(0,last+1),mp(n-(n^sum),last+1));
		last=hor[i].fr;
		int maxreach=0,sumlen=0;
		while(j<m1 && hor[j].fr==hor[i].fr){
			if(maxreach<hor[j].sc.fr) sumlen+=(hor[j].sc.fr-maxreach);
			maxreach=max(maxreach,hor[j].sc.sc);
			++j;
		}
		sumlen+=(n-maxreach);
		if(sumlen&largest){
			int want=sumlen^sum;

			maxreach=0;
			if(want==0) return mp(mp(0,last),mp(n,last));
			j=i;
			while(j<m1 && hor[j].fr==hor[i].fr){
				if(maxreach<hor[j].sc.fr){
					want-=(hor[j].sc.fr-maxreach);
					if(want<=0) return mp(mp(hor[j].sc.fr+want,last),mp(n,last));
				}
				maxreach=max(maxreach,hor[j].sc.fr);
				++j;
			}
			want-=(n-maxreach);
			if(want<=0) return mp(mp(n+want,last),mp(n,last));
		}
		i=j-1;
	}
	if((m-last-1)>0 && (n&largest)) return mp(mp(0,last+1),mp(n-(n^sum),last+1));
}



int main(){
	cin>>n>>m>>k;
	
	REP(i,k){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		
		if(a==c) vert[m2++]=mp(a,mp(b,d));
		else hor[m1++]=mp(b,mp(a,c));
	}
	REP(i,m2) if(vert[i].sc.fr>vert[i].sc.sc) swap(vert[i].sc.fr,vert[i].sc.sc);
	REP(i,m1) if(hor[i].sc.fr>hor[i].sc.sc) swap(hor[i].sc.fr,hor[i].sc.sc);

	sort(vert,vert+m2);
	sort(hor,hor+m1);
	
	REP(i,m2){
		int j=i;
		if((vert[i].fr-last-1)&1) sum^=m;
		last=vert[i].fr;
		int maxreach=0,sumlen=0;
		while(j<m2 && vert[j].fr==vert[i].fr){
			if(maxreach<vert[j].sc.fr) sumlen+=(vert[j].sc.fr-maxreach);
			maxreach=max(vert[j].sc.sc,maxreach);
			++j;
		}
		i=j-1;
		sumlen+=(m-maxreach);
		sum^=sumlen;
	}
	if((n-last-1)&1) sum^=m;
	last=0;
	REP(i,m1){
		int j=i;
		if((hor[i].fr-last-1)&1) sum^=n;
		last=hor[i].fr;
		int maxreach=0,sumlen=0;
		while(j<m1 && hor[j].fr==hor[i].fr){
			if(maxreach<hor[j].sc.fr) sumlen+=(hor[j].sc.fr-maxreach);
			maxreach=max(hor[j].sc.sc,maxreach);
			++j;
		}
		i=j-1;
		sumlen+=(n-maxreach);
		sum^=sumlen;
	}
	if((m-last-1)&1) sum^=n;



	if(sum==0){
		puts("SECOND");
		return 0;
	}

	puts("FIRST");

	pair<pi,pi> a=doit();
	printf("%d %d %d %d\n",a.fr.fr,a.fr.sc,a.sc.fr,a.sc.sc);


	return 0;
}