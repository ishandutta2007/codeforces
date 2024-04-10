#define DEB

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif


template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m,k,p;
int buf[1005][1005];

lint cols[1005],rows[1005];

const lint INF=2e18+10;

lint scores[1000005],scorer[1000005];

void doit(int n,int m,lint* sum,lint* score){
    priority_queue<lint> pq;
    REP(i,n) pq.push(sum[i]);
    score[0]=0;
    REP(i,k){
        lint val=pq.top();pq.pop();
        score[i+1]=score[i]+val;
        
        pq.push(val-p*m);
    }
}

int main(){
    cin>>n>>m>>k>>p;
    REP(i,n) REP(j,m){
        scanf("%d",&buf[i][j]);
        cols[j]+=buf[i][j];
        rows[i]+=buf[i][j];
    }
    
    
    doit(m,n,cols,scores);    
    doit(n,m,rows,scorer);

    
    lint ans=-INF;
    REP(i,k+1){
        chmax(ans,scores[i]+scorer[k-i]-i*(lint)(k-i)*p);
    }
    cout<<ans<<endl;


    






    return 0;
}