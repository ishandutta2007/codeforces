#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
set<int> yh,ya,rh,ra;
string home,away;
int n;
int main(void) {
    cin>>home>>away>>n;
    REP(zz,n) {
        int pos,num;
        string team,card;
        cin>>pos>>team>>num>>card;
        set<int> &y=team=="h"?yh:ya;
        set<int> &r=team=="h"?rh:ra;
        string name=team=="h"?home:away;
        if (r.find(num)!=r.end()) continue;
        if (card=="r") {
            r.insert(num);
            cout<<name<<" "<<num<<" "<<pos<<endl;
        } else {
            if (y.find(num)!=y.end()) {
                r.insert(num);
                y.erase(num);
                cout<<name<<" "<<num<<" "<<pos<<endl;
            } else y.insert(num);
        }
    }
    return 0;
}