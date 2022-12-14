#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4, INF = (int)1e9;
int d[NS];
int N, k;
int arr[NS];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    for(int i=0;i<NS;++i) d[i] = INF;

    int ans = INF;
    for(int i=0;i<N;++i){
        for(int j=arr[i],x=0;;j&=k,++x){
            ans = min(ans, d[j]+x);
            if((j&k)==j) break;
        }
        for(int j=arr[i],x=0;;j&=k,++x){
            d[j] = min(d[j], x);
            if((j&k)==j) break;
        }
    }
    if(ans==INF) puts("-1");
    else printf("%d", ans);

    return 0;
}