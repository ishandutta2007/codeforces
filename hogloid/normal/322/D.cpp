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
int n1,n2,m,n;
int atk[105],def[105];

int ciel[105];
int mark[105];
int main(){
	cin>>n>>m;
	REP(i,n){
		char tmp[15];scanf("%s",tmp);
		int val;cin>>val;

		if(tmp[0]=='A') atk[n1++]=val;
		else def[n2++]=val;
	}
	sort(atk,atk+n1);
	sort(def,def+n2);

	REP(i,m){
		cin>>ciel[i];
	}
	sort(ciel,ciel+m);
	
	int res=0;
	REPN(i,m+1,1){//use cards
		int begin=m-i;
		if(n1<i) continue;
		
		int tmp=0,fail=0;
		REP(j,i){
			int val=atk[j],val2=ciel[begin+j];
			if(val<=val2) tmp+=val2-val;
			else fail=1;
		}
		if(fail) continue;
		res=max(res,tmp);
	}


	if(n<=m){//destroy all
		int fail=0;
		REP(i,n2){
			int p=upper_bound(ciel,ciel+m,def[i])-ciel;

			while(p<m && mark[p]) ++p;
			if(p==m) fail=1;
			else mark[p]=1;
		}
		if(!fail){
			int tmp=0,cnt=n1-1;
			for(int i=m-1;i>=0;--i) if(!mark[i]){
				int val,val2=ciel[i];
				if(cnt>=0) val=atk[cnt];
				else val=0;

				if(val<=val2) tmp+=val2-val;
				else fail=1;
				--cnt;
			}

			if(!fail){
				res=max(res,tmp);
			}
		}
	}
	printf("%d\n",res);

	return 0;
}