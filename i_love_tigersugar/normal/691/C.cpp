#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
string fixNumber(string s) {
    bool allZero=true;
    string res;
    FORE(it,s) {
        if (*it!='0') allZero=false;
        if (!allZero) res.push_back(*it);
    }
    bool haveDot=false;
    FORE(it,res) if (*it=='.') haveDot=true;
    if (haveDot) while (res.back()=='0') res.pop_back();
    if (res.back()=='.') res.pop_back();
    return (res);
}
void process(void) {
    string input; cin>>input;
    string number;
    int oldDotPos;
    REP(i,input.size()) if (input[i]=='.') {
        oldDotPos=i;
        number=input.substr(0,i)+input.substr(i+1,input.size());
    }
    if (number.empty()) {
        number=input;
        oldDotPos=input.size();
    }
    int newDotPos=0;
    REP(i,number.size()) if (number[i]!='0') {
        newDotPos=i+1;
        break;
    }
    cout<<fixNumber(number.substr(0,newDotPos)+"."+number.substr(newDotPos,number.size()));
    if (newDotPos!=oldDotPos) cout<<"E"<<oldDotPos-newDotPos;
    cout<<endl;
}
int main(void) {
    process();
    return 0;
}