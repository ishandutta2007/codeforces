#include<stdio.h>
#include<algorithm>
using namespace std;

int a,b,n,m,ans;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d%d",&a,&b);
            if(a+b)ans++;
        }
    }
    printf("%d",ans);
}