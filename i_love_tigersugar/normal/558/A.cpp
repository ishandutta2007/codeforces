#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
int maxValue(stack<int> left,stack<int> right) {
    int res=0;
    while (true) {
        if (left.empty()) return (res);
        res+=left.top();left.pop();
        if (right.empty()) return (res);
        res+=right.top();right.pop();
    }
}
vector<pair<int,int> > v;
int n;
void process(void) {
    scanf("%d",&n);
    REP(love,n) {
        int x,a;
        scanf("%d%d",&x,&a);
        v.push_back(make_pair(x,a));
    }
    sort(ALL(v));
    vector<int> vl,vr;
    FORE(it,v) {
        if (it->fi<0) vl.push_back(it->se);
        else vr.push_back(it->se);
    }
    reverse(ALL(vr));
    stack<int> left,right;
    FORE(it,vl) left.push(*it);
    FORE(it,vr) right.push(*it);
    printf("%d\n",max(maxValue(left,right),maxValue(right,left)));
}
int main(void) {
    process();
    return 0;
}