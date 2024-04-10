#include <bits/stdc++.h>
using namespace std;

const int NS = 104;
int N, M;
char arr[NS][NS];
int wx[10] = {-1, -1, -1, 0, 1, 1, 1, 0}, wy[10] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(){
    int i, j, x, cnt;
    scanf("%d %d", &N, &M);
    for(i=1;i<=N;i++) for(j=1;j<=M;j++) scanf(" %c", arr[i]+j);
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            if(arr[i][j]!='*'){
                cnt = 0;
                for(x=0;x<8;x++){
                    if(i+wx[x]>=1&&i+wx[x]<=N&&j+wy[x]>=1&&j+wy[x]<=M){
                        if(arr[i+wx[x]][j+wy[x]]=='*') cnt++;
                    }
                }
                if(cnt==0){
                    if(arr[i][j]!='.'){
                        puts("NO");
                        return 0;
                    }
                }
                else{
                    if(arr[i][j]-'0'!=cnt){
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
    }

    puts("YES");

    return 0;
}