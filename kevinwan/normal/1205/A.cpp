#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=0;i<n;i++){
        if(i&1)printf("%d ",2*i+2);
        else printf("%d ",2*i+1);
    }
    for(int i=0;i<n;i++){
        if(i&1)printf("%d ",2*i+1);
        else printf("%d ",2*i+2);
    }
}