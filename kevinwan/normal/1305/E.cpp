#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(time(0));
const int mn=2e5+10;
int a[5010];
int n,m;
void die(){
    if(m)printf("-1");
    else for(int i=1;i<=n;i++)printf("%d ",a[i]);
    exit(0);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)a[i]=1e9-100000*n+i*100000;
    if(n<=2)die();
    a[1]=1,a[2]=2;
    for(int i=3;i<=n;i++){
        if(!m)die();
        if(m-(i-1)/2>=0){
            a[i]=i;
            m-=(i-1)/2;
            continue;
        }
        a[i]=2*i-1-2*m;
        m=0;
        die();
    }
    die();
}