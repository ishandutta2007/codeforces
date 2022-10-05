#include <cstdio>
#include <algorithm>
using namespace std;

char str[100010];
int n;
int cnt[54], kind, allk;

bool can(int k){
    kind = 0;
    for(int i = 1; i <= 52; i++) cnt[i] = 0;
    for(int i = 1; i <= k; i++){
        cnt[str[i]]++;
        if(cnt[str[i]] == 1) kind++;
    }
    if(kind == allk) return true;
    for(int i = k + 1; i <= n; i++){
        cnt[str[i]]++;
        if(cnt[str[i]] == 1) kind++;
        cnt[str[i - k]]--;
        if(cnt[str[i - k]] == 0) kind--;
        if(kind == allk) return true;
    }
    return false;
}

int main(){
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i <= n; i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            str[i] -= 'A';
            str[i] += 1;
        }
        else{
            str[i] -= 'a';
            str[i] += 27;
        }
        cnt[str[i]]++;
        if(cnt[str[i]] == 1) allk++;
    }
    int l = 1, r = n, m;
    while(l <= r){
        m = (l + r) / 2;
        if(can(m)) r = m - 1;
        else l = m + 1;
    }
    printf("%d", l);
}