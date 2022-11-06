#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,c;
    scanf("%d %d",&n,&c);
    int ans=0;
    int a,b=0;
    for(int i=0; i<n; i++){
        scanf("%d",&a);
        ans=max(ans,b-a-c);
        b=a;
    }
    printf("%d\n",ans);
    return 0;
}