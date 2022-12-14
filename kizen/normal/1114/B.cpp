#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, M, k;
int arr[NS], chk[NS];
pair < int, int > srt[NS];

int main(){
    scanf("%d %d %d", &N, &M, &k);
    long long sum = 0;
    for(int i=1;i<=N;++i) scanf("%d", arr+i), srt[i] = make_pair(arr[i], i);
    sort(srt+1, srt+N+1);
    for(int i=N;i>=N-M*k+1;--i){
        chk[srt[i].second] = 1, sum += srt[i].first;
    }
    printf("%lld\n", sum);
    int pos = 1;
    for(int x=1;x<k;++x){
        int cnt = 0;
        while(cnt<M){
            cnt += chk[pos], ++pos;
        }
        printf("%d ", pos-1);
    }
    return 0;
}