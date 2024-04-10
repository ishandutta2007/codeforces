#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int a[mn],b[mn];
int gr(int x){
    if(x==1)return 1;
    if(x==2)return 0;
    if(x==3)return 1;
    if(x==4)return 2;
    if(x&1)return 0;
    int y=gr(x/2);
    if(y==1)return 2;
    return 1;
}
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    if(k&1){
        int sum=0;
        for(i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            sum^=gr(x);
        }
        printf("%s",sum?"Kevin":"Nicky");
    }
    else{
        int sum=0;
        for(i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x==2)sum^=2;
            else if(x==1)sum^=1;
            else sum^=!(x&1);
        }
        printf("%s",sum?"Kevin":"Nicky");
    }
}