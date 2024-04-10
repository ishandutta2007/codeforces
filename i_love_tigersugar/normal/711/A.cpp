#include<bits/stdc++.h>
#define MAX   1111
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
const string yes="YES";
const string no="NO";
string s[MAX];
int n;
void printAnswer(void) {
    cout<<yes<<endl;
    FOR(i,1,n) cout<<s[i]<<"\n";
    exit(0);
}
int main(void) {
    cin>>n;
    FOR(i,1,n) cin>>s[i];
    FOR(i,1,n) {
        if (s[i][0]=='O' && s[i][1]=='O') {
            s[i][0]=s[i][1]='+';
            printAnswer();
        }
        if (s[i][3]=='O' && s[i][4]=='O') {
            s[i][3]=s[i][4]='+';
            printAnswer();
        }
    }
    cout<<no<<endl;
    return 0;
}