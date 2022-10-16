#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const string yes="YES";
const string no="NO";
void answer(const string &ans) {
    cout<<ans<<endl;
    exit(0);
}
bool sameSet(vector<string> s,vector<string> t) {
    sort(ALL(s));
    sort(ALL(t));
    return (s==t);
}
void process(void) {
    string a,b;
    cin>>a>>b;
    int t=a.size();
    while (t%2==0) t/=2;
    vector<string> va,vb;
    REP(i,a.size()/t) {
        va.push_back(a.substr(i*t,t));
        vb.push_back(b.substr(i*t,t));
    }
    while (true) {
        if (!sameSet(va,vb)) answer(no);
        if (va[0].size()==a.size()) answer(yes);
        vector<string> ta,tb;
        REP(i,va.size()/2) {
            string &x=va[2*i];
            string &y=va[2*i+1];
            if (x<y) ta.push_back(x+y); else ta.push_back(y+x);
            string &z=vb[2*i];
            string &t=vb[2*i+1];
            if (z<t) tb.push_back(z+t); else tb.push_back(t+z);
        }
        va=ta;
        vb=tb;
    }
}
int main(void) {
    process();
    return 0;
}