#include <bits/stdc++.h>

using namespace std;

int N, x, y;
int arr[104];

int main(){
    scanf("%d %d %d", &N, &x, &y);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    int ans = 0;
    for(int i=0;i<N;++i) if(x>=arr[i]||x>y) ++ans;
    printf("%d", x<=y? ans/2+ans%2:ans);
    return 0;
}