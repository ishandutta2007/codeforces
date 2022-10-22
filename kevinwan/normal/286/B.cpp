#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=1e6+10;
int a[mn*3];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=2;i<=n;i++){
        int v=a[i-1];
        for(int j=i-1;j<n+i-1;j+=i){
            swap(v,a[min(j+i,n+i-1)]);
        }
    }
    for(int i=n;i<=n+n-1;i++)printf("%d ",a[i]);
}