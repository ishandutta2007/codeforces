#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n;
char s[205];
int main(){
    cin>>n;
    scanf("%s",s);
    
    int cnt=0;
    REP(i,n) if(s[i]=='X') ++cnt;
    
    int dif=cnt-n/2;
    printf("%d\n",abs(dif));
    if(dif>0){
        
    for(int i=0;i<n && dif>0;++i) if(s[i]=='X') s[i]='x',--dif;
    }else for(int i=0;i<n && dif<0;++i){
        if(s[i]=='x') s[i]='X',++dif;
    }

    printf("%s\n",s);
    
    
    
	return 0;
}