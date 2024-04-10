#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int plane(int a,int b,int c,int x,int y) {
    long long t=1LL*a*x+1LL*b*y+c;
    return ((t>0)-(t<0));
}
int main(void) {
    int x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;
    int res=0;
    REP(love,n) {
        int a,b,c;
        cin>>a>>b>>c;
        if (plane(a,b,c,x1,y1)!=plane(a,b,c,x2,y2)) res++;
    }
    cout<<res<<endl;
    return 0;
}