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
int n;
pi box[100005];
int main(){
	cin>>n;

	int res=0;
	REP(i,n){
		scanf("%d%d",&box[i].fr,&box[i].sc);
		
		if(box[i].sc==1) res=max(res,box[i].fr+1);
		else{
			while(box[i].sc>1){
				box[i].sc=(box[i].sc+3)/4;
				++box[i].fr;
			}
			res=max(res,box[i].fr);
		}
	}
	printf("%d\n",res);

	return 0;
}