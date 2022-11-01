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
char s[100010];
int sum[100005],match[100005],maxlen[100005],rightt[100005];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	REP(i,len) sum[i+1]=sum[i]+(s[i]=='['?1:0);
	memset(match,-1,sizeof(match));
	vector<int> stk;
	REP(i,len){
		if(s[i]=='(') stk.pb(i+1);
		else if(s[i]=='[') stk.pb(-(i+1));
		else if(s[i]==']'){
			if(stk.empty() || stk.back()>0){
				while(!stk.empty()) stk.pop_back();
			}else{
				match[-stk.back()-1]=i;
				match[i]=-stk.back()-1;
				stk.pop_back();
			}
		}else if(s[i]==')'){
			if(stk.empty() || stk.back()<0){
				while(!stk.empty()) stk.pop_back();
			}else{
				match[stk.back()-1]=i;
				match[i]=stk.back()-1;
				stk.pop_back();
			}
		}
	}
	int ans=0,l=0,r=0;
	for(int i=len-1;i>=0;--i){
		if(match[i]!=-1 && (s[i]=='[' || s[i]=='(')){
			maxlen[i]=sum[match[i]]-sum[i]+maxlen[match[i]+1];
			if(maxlen[match[i]+1]>0) rightt[i]=rightt[match[i]+1];
			else rightt[i]=match[i]+1;
		}
		if((s[i]=='[' || s[i]=='(') && match[i]!=-1 && maxlen[i]>ans){
			ans=maxlen[i];
			l=i;r=rightt[i];
		}
	}
	printf("%d\n",ans);
	REPN(i,r,l) putchar(s[i]);
	putchar('\n');

	return 0;
}