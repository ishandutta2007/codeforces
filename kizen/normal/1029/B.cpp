#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
int arr[NS];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);

    int ans = 1;
    for(int i=1;i<=N;){
        int cnt = 1;
        int j;
        for(j=i+1;arr[j-1]*2>=arr[j]&&j<=N;++j) ++cnt;
        ans = max(ans, cnt);
        i = j;
    }
    printf("%d", ans);

    return 0;
}