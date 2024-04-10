#include <bits/stdc++.h>
using namespace std;

int N, k;
int chk[104];
vector < int > ans;

int main(){
    int i, a;
    scanf("%d %d", &N, &k);
    for(i=1;i<=N;i++){
        scanf("%d", &a);
        if(k&&!chk[a]){
            chk[a] = 1, k--, ans.push_back(i);
        }
    }
    if(k) puts("NO");
    else{
        puts("YES");
        for(i=0;i<(int)ans.size();i++) printf("%d ", ans[i]);
    }

    return 0;
}