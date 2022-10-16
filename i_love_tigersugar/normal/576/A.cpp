#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int cntDiv[MAX];
bool notPrime[MAX];
void eratosthene(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAX-1) if (!notPrime[i])
        for (int j=2*i;j<MAX;j=j+i) notPrime[j]=true;
    FOR(i,2,MAX-1) if (!notPrime[i])
        for (int j=i;j<MAX;j=j+i) cntDiv[j]++;
}
int main(void) {
    eratosthene();
    int n;
    cin>>n;
    vector<int> res;
    FOR(i,2,n) if (cntDiv[i]==1) res.push_back(i);
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d ",*it); printf("\n");
    return 0;
}