#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
int n,m;
int col[100005];
vi g[100005];
int res[100005];
void dfs(int v,int c){
	col[v]=c;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(col[to]==-1) dfs(to,1-c);
	}
}
void output(int decided){
	dump(decided);
	int gcnt=decided,num=0;
	REP(i,n) if(res[i]==-1 && col[i]==0){
		res[i]=gcnt;
		++num;
		if(num==3){
			num=0;++gcnt;
		}
	}
	REP(i,n) if(res[i]==-1 && col[i]==1){
		res[i]=gcnt;
		++num;
		if(num==3){
			num=0;++gcnt;
		}
	}
	puts("YES");
	REP(i,n) printf("%d%c",res[i]+1,i==n-1?'\n':' ');
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n) sort(ALL(g[i]));
	memset(col,-1,sizeof(col));
	REP(i,n) if(col[i]==-1) dfs(i,0);
	
	int left=0,right=0;
	REP(i,n){
		if(col[i]==0) ++left;
		else ++right;
	}
	memset(res,-1,sizeof(res));
	if(left%3==0 && right%3==0) output(0);
	if(left%3==2){
		REP(i,n) col[i]=1-col[i];
		swap(left,right);
	}
	//left%3==1 right%3==2
	{
		REP(i,n) if(col[i]==0){
			int a=-1,b=-1;
			if((int)g[i].size()<=right-2){
				REP(j,n) if(col[j]==1 && binary_search(ALL(g[i]),j)==false){
					if(a==-1) a=j;
					else if(b==-1){
						b=j;
						break;
					}
				}

				res[a]=res[b]=res[i]=0;
				output(1);
			}
		}
	}
	{
		int a=-1,b=-1;
		REP(i,n) if(col[i]==1 && (int)g[i].size()<=left-2){
			if(a==-1) a=i;
			else{
				b=i;
				break;
			}
		}
		if(b!=-1){
			int a1=-1,b1=-1,a2=-1,b2=-1;
			REP(i,n) if(col[i]==0 && binary_search(ALL(g[a]),i)==false){
				if(a1==-1) a1=i;
				else{
					b1=i;
					break;
				}
			}
			REP(i,n) if(col[i]==0 && binary_search(ALL(g[b]),i)==false){
				if(a2==-1) a2=i;
				else{
					b2=i;
					break;
				}
			}
			res[a]=res[a1]=res[b1]=0;
			res[b]=res[a2]=res[b2]=1;
			output(2);
		}
	}
	puts("NO");


	return 0;
}