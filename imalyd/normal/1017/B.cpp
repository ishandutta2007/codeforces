#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll x[2][2];
char a[100005],b[100005];
int main(){
    scanf("%d%s%s",&n,a,b);
    for(int i=0;i<n;i++){
        int p=a[i]^48,q=b[i]^48;
        ++x[p][0];if(q)++x[p][1];
    }
    cout<<x[0][0]*x[1][0]-x[0][1]*x[1][1];
    return 0;
}