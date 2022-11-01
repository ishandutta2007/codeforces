#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define prl cerr<<"LINE:"<<__LINE__<<" is called"<<endl
using namespace std;
const int INF=5e8;
typedef pair<int,int> pi;
long long p,d;
int main(){
    cin>>p>>d;
    long long nines=0,res=p,tenpow=1;
    REP(i,18){
        if(p>=nines){
            long long tmp=(p-nines)/tenpow*tenpow+nines;
            if(p-tmp<=d) res=tmp;
        }
        nines=10*nines+9;
        tenpow*=10;
    }
    cout<<res<<endl;
    return 0;
}