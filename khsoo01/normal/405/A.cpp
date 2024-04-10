#include<bits/stdc++.h>
using namespace std;
int n,a[105];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}