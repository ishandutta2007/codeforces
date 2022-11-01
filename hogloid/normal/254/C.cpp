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
int dif[30];
char s[100005],s2[100005];
int sum[30][100005];
vector<int> ins;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s%s",s,s2);
	int len=strlen(s);


	REP(i,26) for(int j=len-1;j>=0;--j){
		sum[i][j]=sum[i][j+1]+(s[j]=='A'+i);
	}


	REP(i,len) ++dif[s2[i]-'A'];
	REP(i,len) --dif[s[i]-'A'];

	int cost=0;
	REP(i,26) cost+=max(dif[i],0);

	//dif>0:=ins
	REP(i,26) REP(hoge,dif[i]) ins.pb(i);

	reverse(ALL(ins));

	REP(i,len){
		if(dif[s[i]-'A']<0){
			if(s[i]-'A'<ins.back()){
				
				int fail=0;
				REP(j,26) if(sum[j][i+1]<-dif[j]) fail=1;
				if(fail){
					++dif[s[i]-'A'];
					--dif[ins.back()];
					s[i]=ins.back()+'A';
					ins.pop_back();
				}
			}else{
				++dif[s[i]-'A'];
				--dif[ins.back()];
				s[i]=ins.back()+'A';
				ins.pop_back();
			}
		}
	}
	printf("%d\n%s\n",cost,s);



	return 0;
}