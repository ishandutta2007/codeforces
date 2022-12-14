#include <bits/stdc++.h>

using namespace std;

int N, k;
int arr[104];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;i++) scanf("%d", arr+i);
    int s, e;
    for(s=0;s<N&&arr[s]<=k;s++); s--;
    for(e=N-1;e>=0&&arr[e]<=k;e--); e++;
    if(e<=s) e = s+1;
    printf("%d", s+1+N-e);

    return 0;
}