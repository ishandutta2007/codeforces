#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[7];
int main(void) {
    int sum=0;
    REP(i,4) cin>>a[i];
    string s;
    cin>>s;
    REP(i,s.size()) sum+=a[s[i]-'1'];
    cout<<sum;
    return 0;
}