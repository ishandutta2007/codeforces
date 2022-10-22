#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int a[6],b[6];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<6;i++)a[i]=(n>>i)&1;
    b[0]=a[4];
    b[1]=a[1];
    b[2]=a[3];
    b[3]=a[2];
    b[4]=a[0];
    b[5]=a[5];
    int m=0;
    for(int i=0;i<6;i++)m+=b[i]<<i;
    printf("%d",m);
}