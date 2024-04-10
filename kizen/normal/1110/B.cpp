#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N, M, k;
int arr[NS];
vector < int > sor;

int main(){
    scanf("%d %d %d", &N, &M, &k);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    for(int i=0;i<N-1;++i) sor.push_back(arr[i+1]-arr[i]-1);
    int ans = arr[N-1]-arr[0]+1;
    sort(sor.begin(), sor.end()), reverse(sor.begin(), sor.end());
    --k;
    for(int i=0;k&&i<(int)sor.size();++i) ans -= sor[i], --k;
    printf("%d", ans);
    return 0;
}