#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<set>
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

int h,w,t;
int tf,tu,td;

int buf[305][305];

int lef_cost[305][305][305];//[y][x][len];
int rig_cost[305][305][305];

int vert_cost[305];
typedef pair<int,pair<pi,pi> > anst ;
anst ans;

int main(){
    cin>>h>>w>>t;
    cin>>tf>>tu>>td;
    
    REP(i,h) REP(j,w) scanf("%d",&buf[i][j]);
    REP(i,h) REP(j,w){
        int sum=0;
        for(int k=0;k+j+1<w;++k){
            if(buf[i][j+k+1]>buf[i][j+k]) sum+=tu;
            else if(buf[i][j+k+1]==buf[i][j+k]) sum+=tf;
            else sum+=td;
            
            rig_cost[i][j][k+2]=sum;
        }
        
        sum=0;
        for(int k=0;j-k-1>=0;++k){
            if(buf[i][j-k-1]>buf[i][j-k]) sum+=tu;
            else if(buf[i][j-k-1]==buf[i][j-k]) sum+=tf;
            else sum+=td;
            
            lef_cost[i][j][k+2]=sum;
        }
    }
    
    ans.fr=2e9;

    
    REP(i,w) REPN(j,w,i+2){
        
        set<pi> ever;
        CLR(vert_cost);
        
        int sum=0;
        for(int k=1;k<h;++k){
            if(buf[k][i]<buf[k-1][i]) sum+=tu;
            else if(buf[k][i]==buf[k-1][i]) sum+=tf;
            else sum+=td;
            
            if(buf[k][j]>buf[k-1][j]) sum+=tu;
            else if(buf[k][j]==buf[k-1][j]) sum+=tf;
            else sum+=td;
            
            vert_cost[k]=sum;
        }
         
        for(int k=h-3;k>=0;--k){
            ever.insert(mp(lef_cost[k+2][j][j-i+1]+vert_cost[k+2],
                           k+2));
            
            int now=rig_cost[k][i][j-i+1]-vert_cost[k];
            
            int want=t-now;
            set<pi>::iterator it=ever.lower_bound(mp(want,-1));
            if(it!=ever.end()){
                anst tmp=mp(it->fr-want,mp(mp(k,i),mp(it->sc,j)));
                chmin(ans,tmp);
            }
            if(it!=ever.begin()){
                --it;
                anst tmp=mp(want-it->fr,mp(mp(k,i),mp(it->sc,j)));
                chmin(ans,tmp);
            }
        }
    }
    dump(ans.fr);
    printf("%d %d %d %d\n",ans.sc.fr.fr+1,ans.sc.fr.sc+1,
           ans.sc.sc.fr+1,ans.sc.sc.sc+1);
    
	return 0;
}