#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1LL<<(i))
using namespace std;
typedef long long ll;
int n;
ll exitNode;
bool inSubTree(int h,ll cur) {
    return ((exitNode>>(n-h))==cur);
}
ll countNode(int h,ll cur,int dir) {
    //cerr<<"Count "<<h<<" "<<cur<<" "<<dir<<endl;
    if (h==n) {
        assert(cur==exitNode);
        return (1);
    }
    if (inSubTree(h+1,(cur<<1)|dir)) return (countNode(h+1,(cur<<1)|dir,dir^1)+1);
    else return (MASK(n-h)-1+countNode(h+1,(cur<<1)|(dir^1),dir)+1);
}
int main(void) {
    cin>>n>>exitNode;
    exitNode--;
    cout<<countNode(0,0,0)-1<<endl;
    return 0;
}