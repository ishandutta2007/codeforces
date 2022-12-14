#include <bits/stdc++.h>

using namespace std;

int N, k;
int arr[5004], cnt[5004], val[5004];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;++i) scanf("%d", arr+i), ++cnt[arr[i]];
    for(int i=0;i<5004;++i) if(cnt[i]>k){
        puts("NO"); return 0;
    }
    val[0] = cnt[0];
    for(int i=1;i<5004;++i) val[i] = cnt[i]+val[i-1];
    for(int i=1;i<5004;++i) val[i] = val[i]-cnt[i]+1;
    puts("YES");
    for(int i=0;i<N;++i) printf("%d ", (val[arr[i]]++-1)%k+1);
    return 0;
}