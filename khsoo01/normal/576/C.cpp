#include<bits/stdc++.h>
using namespace std;
int n;

struct zp{
    int x,y,idx;
}a[1000005];

vector<zp>buck[1005][1005];
bool comp(zp A,zp B) {return A.y<B.y;}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].idx=i+1;
    }
    sort(a,a+n,comp);
    for(i=0;i<n;i++) {
        buck[a[i].x/1000][a[i].y/1000].push_back(a[i]);
    }
    for(i=0;i<=1000;i++) {
        if(i%2==0) {
            for(j=0;j<=1000;j++) {
                for(k=0;k<buck[i][j].size();k++) {
                    printf("%d ",buck[i][j][k].idx);
                }
            }
        }
        else {
            for(j=1000;j>=0;j--) {
                for(k=buck[i][j].size()-1;k>=0;k--) {
                    printf("%d ",buck[i][j][k].idx);
                }
            }
        }
    }
}