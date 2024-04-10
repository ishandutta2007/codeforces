#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[1004];
int way[1004][1004], wayN[1004], waypos[1004];
int waycnt;

int main(){
    scanf("%d", &N);
    for(int i=1;i<N;++i){
        int A, B;
        scanf("%d %d", &A, &B);
        if((A!=N&&B!=N)||(A==N&&B==N)){
            puts("NO");
            return 0;
        }
        if(B==N) ++cnt[A];
        else ++cnt[B];
    }
    for(int i=N-1;i>=1;--i){
        if(cnt[i]){
            wayN[++waycnt] = cnt[i], waypos[waycnt] = 1;
            way[waycnt][cnt[i]] = i, way[waycnt][0] = N;
        }
        else{
            int f = 1;
            for(int j=1;j<=waycnt;++j){
                if(waypos[j]<wayN[j]){
                    way[j][waypos[j]] = i, ++waypos[j];
                    f = 0; break;
                }
            }
            if(f){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=1;i<=waycnt;++i) for(int j=0;j<wayN[i];++j) printf("%d %d\n", way[i][j], way[i][j+1]);
    return 0;
}