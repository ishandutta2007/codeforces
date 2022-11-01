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
string s;
pi range[15];
string p[15];
set<string> done;

lint hash[15][2005];

lint hash2[2005];
lint powB[2005];
lint B=100000007;

lint all[2100000];
int appear[11][2100005];	
int main(){
	powB[0]=1;
	REP(i,2001) powB[i+1]=powB[i]*B;

	cin>>s>>n;
	REP(i,s.size()) hash2[i+1]=hash2[i]*B+s[i];
	
	int cnt=0;
	int ms=s.size();
	REP(i,ms){
		REPN(j,ms,i){
			lint tmp=hash2[j+1]-hash2[i]*powB[j-i+1];
			all[cnt++]=tmp;
		}
	}
	sort(all,all+cnt);
	cnt=unique(all,all+cnt)-all;

	REP(i,n){
		cin>>p[i]>>range[i].fr>>range[i].sc;
		
		int m=p[i].size();
		REP(j,m) hash[i][j+1]=hash[i][j]*B+p[i][j];
		
		REP(j,m) REPN(k,m,j){
			lint tmp=hash[i][k+1]-hash[i][j]*powB[k-j+1];
			if(binary_search(all,all+cnt,tmp)){
				int p=lower_bound(all,all+cnt,tmp)-all;
				appear[i][p]++;
			}
		}
	}
	
	int res=0;
	REP(i,cnt){
		int fail=0;
		REP(j,n) if(appear[j][i]<range[j].fr || range[j].sc<appear[j][i]) fail=1;
		if(!fail) ++res;
	}

	printf("%d\n",res);
	return 0;
}