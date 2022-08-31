#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
int main(){
    scanf("%d",&n);
    int mn=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(a[i]>=0){
            a[i]=-a[i]-1;
        }
        mn=min(mn,a[i]);
    }
    if(n&1){
        for(int i=1;i<=n;++i){
            if(a[i]==mn){
                a[i]=-a[i]-1;
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",a[i]);
    }
    return 0;
}