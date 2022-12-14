#include <bits/stdc++.h>

using namespace std;

int N;
char arr[504][504];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%s", arr[i]+1);
    int ans = 0;
    for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) if(arr[i][j]=='X'&&arr[i-1][j-1]=='X'&&arr[i-1][j+1]=='X'&&arr[i+1][j-1]=='X'&&arr[i+1][j+1]=='X') ++ans;
    printf("%d", ans);
    return 0;
}