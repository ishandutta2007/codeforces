//Problem B
#include<bits/stdc++.h>
using namespace std;

int n,a[1007],v[1007];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        int cur=i;v[i]=1;
        while(1){
            if(v[cur=a[cur]]){printf("%d ",cur);break;}
            v[cur]=1;
        }
    }
    return 0;
}