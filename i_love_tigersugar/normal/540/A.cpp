#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int add(int n,int x,int y) {
    return (x<=y?y-x:n-x+y);
}
int sub(int n,int x,int y) {
    return (x>=y?x-y:n-y+x);
}
int main(void) {
    int n;
    string a,b;
    cin>>n>>a>>b;
    int res=0;
    REP(i,n) res+=min(add(10,a[i]-'0',b[i]-'0'),sub(10,a[i]-'0',b[i]-'0'));
    cout<<res<<endl;
    return 0;
}