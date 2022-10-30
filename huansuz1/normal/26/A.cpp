#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define mp make_pair
#define f first
#define s second

using namespace std;

int n,m,a[3456],b[3000],ans;

int main(){
a[1]=2;
m=1;
for (int i=3; i<=3000; i++){
    int p=0;
    for (int j=2; j*j<=i; j++)
        if (i%j==0) {p=1; break; }
    if (p==0) {m++; a[m]=i;}
}
cin>>n;
for (int i=6; i<=n; i++){
    int z=0;
    for (int j=1; j<=m; j++){
        if (a[j]>=i) break;
        if (i%a[j]==0 && a[j]<i) z++;
    }
    if (z==2) {ans++;}
}
cout<<ans;


return 0;
}