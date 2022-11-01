#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

char s[3000005];
int n;
int ans=1;
bool vis[1000005];
void check(int t){
	int res=0;
	memset(vis,0,sizeof(vis));
	for(int i=t;i<t+n;++i){
		++res;
		int j=i;
		vis[i%n]=1;
		if(s[i]=='0'){
			while(s[j]==s[i]){
				if(vis[(j+1)%n]) --res;
				++j;
			}
		}else{
			while(s[j]==s[i]){
				if(vis[(j+1)%n]) --res;
				++j;
			}
		}
		i=j;
			
	}
	ans=max(ans,res);
}


int main(){
	scanf("%s",s);
	n=strlen(s);
	REP(i,n) s[i+n]=s[i+n+n]=s[i];
	
	check(0);
	check(1);
	check(2);

	cout<<ans<<endl;

	return 0;
}