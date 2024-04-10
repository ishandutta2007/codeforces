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
string str;
int allow;
string roundUp(string str, int pos) {
    str = str.substr(0, pos);
    str = "0" + str;
    int id = str.size() - 1;
    while (true) {
        if (str[id] == '.') {
            id--;
            continue;
        }
        if (str[id] != '9') {
            str[id]++;
            break;
        }
        str[id] = '0';
        id--;
    }
    if (str.back () == '.') str.pop_back();
    return str.substr(str[0] == '0' ? 1 : 0, str.size());
}
string addOne(string str) {
    str = "0" + str;
    int id = (int) str.size() - 1;
    while (id >= 0 && str[id] == '9') {
        str[id] = '0';
        id--;
    }
    str[id]++;
    return str.substr(str[0] == '0' ? 1 : 0, str.size());
}
void process(void) {
    cin >> allow >> allow >> str;
    int dotPos = str.find('.');
    FOR(i, dotPos + 1, (int)str.size() - 1) if (str[i] >= '5') {
        str = roundUp(str, i);
        allow--;
        if (str.find('.') < str.size()) {
            while (allow > 0  && str.back() != '.' && str.back() >= '5') {
                str.pop_back();
                if (str.back() == '.') {
                    str.pop_back();
                    str = addOne(str);
                    break;
                } else str.back()++;
                allow--;
            }
        }
        while (!str.empty() && str.back() == '.') str.pop_back();
        while (!str.empty() && str.front() == '0') str = str.substr(1, str.size());
        if (str.front() == '.') str = "0" + str;
        cout << str << endl;
        return;
    }
    cout << str << endl;
}
int main(void) {
    process();
    return 0;
}