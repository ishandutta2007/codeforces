#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
const int INF=(int)1e9+7;
const int num=1000000;
int c,hr,hb,wr,wb;
long long res;
bool valid(long long r,long long b) {
    return (r>=0 && b>=0 && r<INF && b<INF && 1LL*wr*r+1LL*wb*b<=c);
}
long long value(int r,int b) {
    return (1LL*hr*r+1LL*hb*b);
}
int main(void) {
    cin>>c>>hr>>hb>>wr>>wb;
    FOR(r,0,num) if (valid(r,(c-1LL*wr*r)/wb)) res=max(res,value(r,(c-1LL*wr*r)/wb));
    FOR(b,0,num) if (valid((c-1LL*wb*b)/wr,b)) res=max(res,value((c-1LL*wb*b)/wr,b));
    FOR(r,c/(wr+wb)-num,c/(wr+wb)+num) if (valid(r,(c-1LL*wr*r)/wb)) res=max(res,value(r,(c-1LL*wr*r)/wb));
    FOR(b,c/(wr+wb)-num,c/(wr+wb)+num) if (valid((c-1LL*wb*b)/wr,b)) res=max(res,value((c-1LL*wb*b)/wr,b));
    cout<<res<<endl;
    return 0;
}