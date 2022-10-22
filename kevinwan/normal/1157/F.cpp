#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int a[mn],b[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<mn;i++)b[i]=b[i-1]+a[i];
    int l=0,bes=0,q=0,w=0;
    for(int i=1;i<mn;i++){
        if(a[i]<2){
            if(b[i]-b[max(l-1,0)]>bes)bes=b[i]-b[max(l-1,0)],q=l,w=i;
            l=i;
        }
    }
    printf("%d\n",bes);
    for(int i=q;i<=w;i++)if(a[i])printf("%d ",i);
    for(int i=w;i>=q;i--)for(int j=0;j<a[i]-1;j++)printf("%d ",i);
}