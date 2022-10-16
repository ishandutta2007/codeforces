#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define se   second
using namespace std;
const int mod=(int)1e9+7;
string s;
int main(void) {
    int n;
    cin>>n>>s;
    map<int,int> cnt;
    FORE(it,s) cnt[*it]++;
    int maxVal=0;
    int cntMax=0;
    FORE(it,cnt) {
        if (it->se>maxVal) {
            maxVal=it->se;
            cntMax=1;
        } else if (it->se==maxVal) cntMax++;
    }
    int res=1;
    REP(love,n) res=1LL*res*cntMax%mod;
    cout<<res<<endl;
    return 0;
}