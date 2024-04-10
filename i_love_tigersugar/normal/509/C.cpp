#include<bits/stdc++.h>
#define MAX   333
#define NDIG   357
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
bool f[NDIG+7][MAX][2];
int n;
int getDig(const string &prev,int id) {
    return (id<prev.size()?prev[id]-'0':0);
}
void addOne(string &s) {
    reverse(s.begin(),s.end());
    int id=0;
    while (id<s.size() && s[id]=='9') {
        s[id]='0';
        id++;
    }
    if (id<s.size()) s[id]++; else s.push_back('1');
    reverse(s.begin(),s.end());
}
string findNumber(int s,string prev) {
    reverse(prev.begin(),prev.end());
    memset(f,false,sizeof f);
    f[0][0][1]=true;
    REP(i,NDIG) REP(j,s+1) REP(k,2) if (f[i][j][k])
        REP(t,10) if (j+t<=s) {
            int x=getDig(prev,i);
            f[i+1][j+t][t>x || (t==x && k)]=true;
        }
    //assert(f[NDIG][s][1]);
    int curSum=0;
    bool curEqu=true;
    string res;
    FOR(i,1,NDIG) FOR(j,0,9) if (curSum+j<=s && (!curEqu || j>=getDig(prev,NDIG-i))) {
        int nextSum=curSum+j;
        bool nextEqu=curEqu && j==getDig(prev,NDIG-i);
        bool ok=nextEqu?f[NDIG-i][s-nextSum][1]:f[NDIG-i][s-nextSum][0]||f[NDIG-i][s-nextSum][1];
        if (ok) {
            if (!res.empty() || j>0) res.push_back(j+'0');
            curSum=nextSum;
            curEqu=nextEqu;
            break;
        }
    }
    return (res);
}
int main(void) {
    int n;
    cin>>n;
    string prev="1";
    REP(zz,n) {
        int s;
        cin>>s;
        string cur=findNumber(s,prev);
        cout<<cur<<"\n";
        prev=cur;
        addOne(prev);
    }
    return 0;
}