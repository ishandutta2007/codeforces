#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    const int s = 1000000;
    static bool used[s] = {};
    int n;
    cin >> n;
    REP(i, n) {
        int x;
        scanf("%d", &x);
        x--;
        used[x] = true;
    }
    int size = 0;
    static int ans[s] = {};
    int que = 0;
    for(int i = 0; i < s; i++){
        int j = s - 1 - i;
        if(j < i) break;
        if(used[i] && used[j]){
            que++;
        }
    }
    for(int i = 0; i < s; i++){
        int j = s - 1 - i;
        //printf("i = %d j = %d\n", i, j);
        assert(i != j);
        if(j < i) break;
        if(used[i] && used[j]){
        }else if(used[i]){
            ans[size++] = j + 1;
        }else if(used[j]){
            ans[size++] = i + 1;
        }else if(que > 0){
            que--;
            ans[size++] = i + 1;
            ans[size++] = j + 1;
        }
    }
    printf("%d\n", size);
    for(int i = 0; i < size; i++){
        printf("%d", ans[i]);
        if(i == size - 1) puts("");
        else printf(" ");
    }

    return 0;
}