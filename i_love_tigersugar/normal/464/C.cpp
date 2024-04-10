#include<cstdio>
#include<iostream>
#include<string>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
int hash[10],mul[10];
string que[MAX];
string a;
int q;
void init(void) {
    cin>>a>>q;
    FOR(i,1,q) cin>>que[i];
}
void process(void) {
    REP(i,10) {
        hash[i]=i;
        mul[i]=10;
    }
    FORD(i,q,1) {
        int t=que[i][0]-'0';
        string s=que[i].substr(3);
        int h=0;
        int p=1;
        FORE(it,s) {
            h=(1LL*h*mul[*it-'0']+hash[*it-'0'])%mod;
            p=1LL*p*mul[*it-'0']%mod;
        }
        hash[t]=h;
        mul[t]=p;
        //printf("HASH %d = %d %d\n",t,h,p);
    }
    int res=0;
    FORE(it,a) res=(1LL*res*mul[*it-'0']+hash[*it-'0'])%mod;
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}