#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
string s,t;
map<char,int> cnt;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>s>>t;
    int cntSame,cntDiff;
    cntSame=cntDiff=0;
    REP(i,s.size()) cnt[s[i]]--;
    REP(i,t.size()) {
        if (cnt[t[i]]<0) cntSame++;
        cnt[t[i]]++;
    }
    FOR(i,'a','z') {
        int j=i-'a'+'A';
        if (cnt[i]>0 && cnt[j]<0) cntDiff+=min(cnt[i],-cnt[j]);
        if (cnt[i]<0 && cnt[j]>0) cntDiff+=min(-cnt[i],cnt[j]);
    }
    cout<<cntSame<<" "<<cntDiff<<endl;
    return 0;
}