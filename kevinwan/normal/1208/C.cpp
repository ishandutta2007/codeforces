#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e3+10;
int a[mn][mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j,k,l;
    cin>>n;
    int cur=0;
    for(i=0;i<n/4;i++){
        for(j=0;j<n/4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    a[i*4+k][j*4+l]=cur++;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}