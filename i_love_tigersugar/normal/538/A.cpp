#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string goal="CODEFORCES";
const string yes="YES";
const string no="NO";
int main(void) {
    string s;
    cin>>s;
    REP(i,s.size()) FOR(j,i,(int)s.size()-1) {
        string tmp;
        if (i>0) tmp+=s.substr(0,i);
        if (j<(int)s.size()-1) tmp+=s.substr(j+1,s.size());
        if (tmp==goal) {
            cout<<yes<<endl;
            return 0;
        }
    }
    cout<<no<<endl;
    return 0;
}