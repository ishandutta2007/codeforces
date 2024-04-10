#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
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

int n,s;
pair<pi,int> city[1005];
bool cmp(const pair<pi,int>& a,const pair<pi,int>&b ){
    return a.fr.fr*a.fr.fr+a.fr.sc*a.fr.sc<b.fr.fr*b.fr.fr+
    b.fr.sc*b.fr.sc;
}
int main(){
    cin>>n>>s;
    REP(i,n) cin>>city[i].fr.fr>>city[i].fr.sc>>city[i].sc;
    
    sort(city,city+n,cmp);
    
    REP(i,n){
        s+=city[i].sc;
        if(s>=1000000){
            double res=city[i].fr.fr*city[i].fr.fr+city[i].fr.sc*
            city[i].fr.sc;
            res=sqrt(res);
            printf("%.12f\n",res);
            return 0;
        }
    }
    puts("-1");
    
	return 0;
}