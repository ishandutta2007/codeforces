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
int n,k;
char s[500005],tmp[500005];
int main(){
    scanf("%d%d%s",&n,&k,s);
    if(n==1){
        printf("%d\n%s\n",0,s);
        return 0;
    }
    int res=0;
    if(k>=3){
        REP(i,n-1) if(s[i+1]==s[i]){
            ++res;
            REP(j,k) if(j!=s[i]-'A' && (i==n-2 || s[i+2]-'A'!=j)){
                s[i+1]='A'+j;
                break;
            }
        }
    }else{
        int tres=0;
        REP(i,n) tmp[i]='A'+(i&1);
        REP(i,n) if(s[i]!=tmp[i]) ++tres;
        if(tres*2<n){
            REP(i,n) s[i]=tmp[i];
            res=tres;
        }else{
            REP(i,n) s[i]='A'+((i&1)^1);
            res=n-tres;
        }
    }

    printf("%d\n%s\n",res,s);
    return 0;
}