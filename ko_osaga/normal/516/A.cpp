#include <cstdio>

int cnt[9];

int main(){
    int n;
    char str[20];
    scanf("%d",&n);
    scanf("%s",str);
    for (int i=0; i<n; i++) {
        int p = str[i] - '0';
        for (int p=2; p<=str[i] - '0'; p++) {
            int p2 = p;
            for (int j=2; j<9; j++) {
                while (p2 % j == 0) {
                    cnt[j]++;
                    p2 /= j;
                }
            }
        }
    }
    for (int i=0; i<cnt[7]; i++) {
        printf("%d",7);
    }
    cnt[5] -= cnt[7];
    cnt[3] -= cnt[7] * 2;
    cnt[2] -= cnt[7] * 4;
    for (int i=0; i<cnt[5]; i++) {
        printf("%d",5);
    }
    cnt[3] -= cnt[5];
    cnt[2] -= cnt[5] * 3;
    for (int i=0; i<cnt[3]; i++) {
        printf("%d",3);
    }
    cnt[2] -= cnt[3];
    for (int i=0; i<cnt[2]; i++) {
        printf("%d",2);
    }
}