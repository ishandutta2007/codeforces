#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
typedef pair<int,int> pi;
void solve(lint x1,lint x2,lint a,lint b,int swapped){
    lint dif=x2-x1;
    if(a<=0){
        if(dif>b) puts("DRAW");
        else{
            puts("FIRST");
            if(swapped) cout<<x1<<endl;
            else cout<<x2<<endl;
        }
    }else{
        dif%=a+b;
        if(dif==0) puts("SECOND");
        else if(dif<a) puts("DRAW");
        else if(dif<=b){
            puts("FIRST");
            if(swapped){
                cout<<x2-dif<<endl;
            }else{
                cout<<x1+dif<<endl;
            }
        }else puts("DRAW");
    }
}
lint x1,x2,a,b;
int main(){
    cin>>x1>>x2>>a>>b;
    if(x1<x2){
        if(b>0) solve(x1,x2,a,b,0);
        else puts("DRAW");
    }else{
        if(a<0) solve(x2,x1,-b,-a,1);
        else puts("DRAW");
    }
    return 0;
}