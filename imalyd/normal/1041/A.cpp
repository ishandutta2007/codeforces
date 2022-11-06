//Problem A
#include<bits/stdc++.h>
using namespace std;

int n,a,mn,mx;

int main(){
    scanf("%d%d",&n,&a),mn=mx=a;
    for(int i=1;i<n;i++)scanf("%d",&a),mn=min(mn,a),mx=max(mx,a);
    printf("%d",mx-mn+1-n);
    return 0;
}