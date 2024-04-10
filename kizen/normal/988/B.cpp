#include <bits/stdc++.h>
using namespace std;

int N;
struct data{
    char s[104]; int num;
    bool operator<(const data&r)const{
        return num>r.num;
    }
}arr[104];

bool in(int a, int b){
    int na = strlen(arr[a].s), nb = strlen(arr[b].s);
    int i, j, f;
    for(i=0;i<=nb-na;i++){
        f = 1;
        for(j=i;j<i+na;j++) if(arr[a].s[j-i]!=arr[b].s[j]){
            f = 0; break;
        }
        if(f) return 1;
    }
    return 0;
}

int main(){
    scanf("%d", &N);
    int i, j;
    for(i=1;i<=N;i++){
        scanf("%s", arr[i].s);
    }
    for(i=1;i<=N;i++) for(j=1;j<=N;j++) if(in(i, j)) arr[i].num++;
    sort(arr+1, arr+N+1);
    int f = 1;
    for(i=2;i<=N;i++) if(!in(i-1, i)){
        f = 0; break;
    }
    if(!f) puts("NO");
    else{
        puts("YES");
        for(i=1;i<=N;i++) printf("%s\n", arr[i].s);
    }

    return 0;
}