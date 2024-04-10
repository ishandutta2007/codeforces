#include <bits/stdc++.h>

using namespace std;
int freq[5010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d",&a);
        freq[a]++;
    }
    int ans=0;
    for(int i=1; i<5010; i++){
        if(freq[i]>1&&i<=n)ans+=freq[i]-1;
        else if(i>n) ans+=freq[i];
    }
    printf("%d\n",ans);
    return 0;
}