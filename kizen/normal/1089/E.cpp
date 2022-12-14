#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    for(int i=1;i<=8;++i){
        if(i==8){
            printf("b%d ", i);
            if(N>=2) printf("a%d ", i);
            for(int j=2;j<N;++j) printf("%c%d ", 'a'+j, i);
            printf("h8", i);
            return 0;
        }
        else if(i%2==1){
            if(N<=8){
                if(N>=2){
                    for(int j=1;j<N;++j) printf("%c%d ", 'a'+j-1, i);
                    printf("h%d h8", i);
                    return 0;
                }
                else{
                    printf("a8 h8"); return 0;
                }
            }
            printf("a%d ", i);
            for(int j=8;j>=2;--j) printf("%c%d ", 'a'+j-1, i);
            N -= 8;
        }
        else{
            if(N<=8){
                if(N>=2){
                    printf("b%d ", i);
                    if(N>=3) printf("a%d ", i);
                    for(int j=3;j<N;++j) printf("%c%d ", 'a'+j-1, i);
                    printf("h%d h8", i);
                    return 0;
                }
                else{
                    printf("b8 h8"); return 0;
                }
            }
            printf("b%d ", i);
            for(int j=8;j>=3;--j) printf("%c%d ", 'a'+j-1, i);
            printf("a%d ", i);
            N -= 8;
        }
    }
    return 0;
}