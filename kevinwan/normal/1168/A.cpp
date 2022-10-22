#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int a[mn],b[mn],n,m;
bool ok(int x){
    memcpy(a,b,sizeof(a));
    int at=0,i;
    for(i=0;i<n;i++){
        if(a[i]<at){
            if(at-a[i]>x)return 0;
        }
        else if((at+m-a[i])%m<=x)continue;
        else at=a[i];
    }
    return 1;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",a+i);
    memcpy(b,a,sizeof(a));
    int l=-1;
    for(i=1<<18;i;i>>=1){
        if(!ok(i+l))l+=i;
    }
    printf("%d",l+1);
}