#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
bool sameLine(const pair<int,int> &a,const pair<int,int> &b) {
    return (1LL*a.fi*b.se==1LL*a.se*b.fi);
}
int main(void) {
    int n,u,v;
    scanf("%d%d%d",&n,&u,&v);
    vector<pair<int,int> > tmp;
    REP(love,n) {
        bool ok=false;
        int x,y;
        scanf("%d%d",&x,&y);
        pair<int,int> cur(x-u,y-v);
        FORE(it,tmp) if (sameLine(*it,cur)) ok=true;
        if (!ok) tmp.push_back(cur);
    }
    cout<<tmp.size()<<endl;
    return 0;
}