#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
set<int> lineX,lineY;
multiset<int> lenX,lenY;
void process(void) {
    int w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    lineX.insert(0);
    lineX.insert(w);
    lineY.insert(0);
    lineY.insert(h);
    lenX.insert(w);
    lenY.insert(h);
    REP(love,n) {
        char type[3];
        int t;
        scanf("%s",type);
        scanf("%d",&t);
        set<int> &line=type[0]=='V'?lineX:lineY;
        multiset<int> &len=type[0]=='V'?lenX:lenY;
        __typeof(line.begin()) it=line.upper_bound(t);
        int R=*it; it--;
        int L=*it;
        len.erase(len.find(R-L));
        len.insert(R-t);
        len.insert(t-L);
        line.insert(t);
        __typeof(lenX.begin()) jt=lenX.end();jt--;
        int X=*jt;
        jt=lenY.end();jt--;
        int Y=*jt;
        cout<<1LL*X*Y<<"\n";
    }
}
int main(void) {
    process();
    return 0;
}