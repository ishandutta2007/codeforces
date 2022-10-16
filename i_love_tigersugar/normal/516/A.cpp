#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
string add[]={"","","2","3","223","5","35","7","2227","2337"};
int main(void) {
    vector<int> v;
    string s;
    cin>>s>>s;
    FORE(it,s) FORE(jt,add[*it-'0']) v.push_back(*jt-'0');
    sort(v.begin(),v.end(),greater<int>());
    FORE(it,v) printf("%d",*it); printf("\n");
    return 0;
}