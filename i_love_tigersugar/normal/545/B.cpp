#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string noAns="impossible";
string s,t;
vector<int> diffPos;
int n;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>s>>t;
    n=s.size();
    REP(i,n) if (s[i]!=t[i]) diffPos.push_back(i);
    if (diffPos.size()%2==1) cout<<noAns<<endl;
    else {
        string res(n,'0');
        REP(i,n) if (s[i]==t[i]) res[i]=s[i];
        REP(i,diffPos.size()) res[diffPos[i]]=i%2?s[diffPos[i]]:t[diffPos[i]];
        cout<<res<<endl;
    }
    return 0;
}