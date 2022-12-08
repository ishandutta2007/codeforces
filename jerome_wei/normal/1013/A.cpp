#include<bits/stdc++.h>

using namespace std;

int a[1000],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    int ans=0;
    for(int b,j=1;j<=n;j++){
	scanf("%d",&b);
	ans+=a[j]-b;
    }
    if(ans<0)printf("No\n");
    else printf("Yes\n");
    return 0;
}