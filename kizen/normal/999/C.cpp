#include <bits/stdc++.h>

using namespace std;

const int NS = 4*(1e5)+4;
int N, k;
char arr[NS];
int cnt[30], ord[NS];

int main(){
    scanf("%d %d", &N, &k);
    scanf("%s", arr);

    for(int i=0;i<N;i++){
        cnt[arr[i]-'a']++;
        ord[i] = cnt[arr[i]-'a'];
    }
    for(int i=1;i<26;i++) cnt[i] += cnt[i-1];
    for(int i=0;i<N;i++) ord[i] += cnt[arr[i]-'a'-1];
    for(int i=0;i<N;i++) if(ord[i]>k) printf("%c", arr[i]);

    return 0;
}