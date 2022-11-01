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
int k;
char s[1005];
int appear[30];
int main(){
    scanf("%d%s",&k,s);
    int len=strlen(s);
    REP(i,len) appear[s[i]-'a']++;
    int fail=0;
    REP(i,26) if(appear[i]%k) fail=1;
    if(fail){
        puts("-1");
        return 0;
    }
    REP(i,k){
        int div=len/k;
        REP(j,26){
            REP(j2,appear[j]/k) putchar('a'+j);
        }
    }
    putchar('\n');

    return 0;
}