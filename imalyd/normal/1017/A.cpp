#include<bits/stdc++.h>
using namespace std;

int n;
struct lyd{int a,id;}l[1005];
bool cmp(lyd a,lyd b){if(a.a==b.a)return a.id<b.id;return a.a>b.a;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        l[i].id=i;
        for(int j=0,x;j<4;j++)scanf("%d",&x),l[i].a+=x;
    }
    sort(l+1,l+n+1,cmp);
    for(int i=1;i<=n;i++)if(l[i].id==1)printf("%d",i);
    return 0;
}