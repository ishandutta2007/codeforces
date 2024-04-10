#include<bits/stdc++.h>
using namespace std;
const string yes="YES";
const string no="NO";
int w,x;
bool ok(int x,int n) {
    if (x==0) return (true);
    if (n==0) return (-1<=x && x<=1);
    if (x%w==0) return (ok(x/w,n-1));
    if ((x-1)%w==0) return (ok((x-1)/w,n-1));
    if ((x+1)%w==0) return (ok((x+1)/w,n-1));
    return (false);
}
int main(void) {
    cin>>w>>x;
    cout<<(ok(x,100)?yes:no)<<endl;
    return 0;
}