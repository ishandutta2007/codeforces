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
int n,k;
char line[4][10005];
int len[4],num[4];
int vow[300];
string suf[4];
int match[4][4];
int judge(){
	memset(match,0,sizeof(match));
	memset(num,0,sizeof(num));
	REP(j,4){
		suf[j].clear();
		scanf("%s",line[j]);
		len[j]=strlen(line[j]);
		for(int j2=len[j]-1;j2>=0;--j2){
			suf[j]+=line[j][j2];
			if(vow[line[j][j2]]){
				++num[j];
				if(num[j]>=k) break;
			}
		}
		reverse(ALL(suf[j]));
		if(num[j]<k) return 0;
		REP(i,j) if(suf[j]==suf[i]){
			match[i][j]=match[j][i]=1;
		}
	}
	if(match[0][1] && match[2][3] && match[1][2]) return 7;
	if(match[0][1] && match[2][3]) return 1;
	if(match[0][2] && match[1][3]) return 2;
	if(match[0][3] && match[1][2]) return 4;
	return 0;
}
char ans[10][10]={
	"NO","aabb","abab","","abba","","","aaaa"};
int main(){
	vow['a']=vow['i']=vow['o']=vow['u']=vow['e']=1;
	cin>>n>>k;
	int mask=7;
	REP(i,n) mask&=judge();
	printf("%s\n",ans[mask]);



	return 0;
}