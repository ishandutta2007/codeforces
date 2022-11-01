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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cout<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int appear[100005];
int num[100005];
bool solve(){
    int mini=*min_element(num,num+n);
    int last=0;
    REP(i,n){
        num[i]-=mini;
        if(num[i]>=100005){
            return false;
        }
        last=max(last,num[i]);
        ++appear[num[i]];
    }
    REP(i,last+1){
        if(appear[i]>0){
            if(i==last && appear[i]==0) return true;
            if(appear[i+1]<=appear[i]){
                if(i+1==last && appear[i]==appear[i+1]) return true;
                return false;
            }
            appear[i+1]-=appear[i];
        }
    }
    return true;
}



int main(){
    scanf("%d",&n);
    REP(i,n) scanf("%d",&num[i]);
    if(solve()) puts("YES");
    else puts("NO");
    return 0;
}