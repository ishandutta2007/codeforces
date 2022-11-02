#include<bits/stdc++.h>
using namespace std;
char ipt[105];

int dist (char a, char b) {
    if(a > b) swap(a, b);
    return min(b-a, ('z'-b) + (a-'a') + 1);
}

int main()
{
    scanf("%s",&ipt);
    int len = strlen(ipt);
    char cur = 'a';
    int ans = 0;
    for(int i=0;i<len;i++) {
        ans += dist(cur, ipt[i]);
        cur = ipt[i];
    }
    printf("%d\n",ans);
}