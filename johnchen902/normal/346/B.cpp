#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s1[101], s2[101], virus[101];

enum Dir { left, top, twod, threed };
int dp[101][101][101];
Dir dir[101][101][101];
int failure[101][26];

int main(){
    scanf("%s%s%s", s1, s2, virus);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int lv = strlen(virus);
    for(int i = 0; i < lv; i++) {
        for(int j = 'A'; j <= 'Z'; j++) {
            if(virus[i] != j) {
                failure[i][j - 'A'] = lv;
                for(int k = i + 1; k < lv; k++) {
                    if(j == virus[k] && !strncmp(virus + i + 1, virus + k + 1, lv - k - 1)) {
                        failure[i][j - 'A'] = k;
                        break;
                    }
                }
            }
        }
    }
//    for(int i = 0; i < lv; i++) {
//        for(int j = 'A'; j <= 'Z'; j++)
//            printf("%d ", failure[i][j - 'A']);
//        puts("");
//    }
    for(int i = 0; i <= l1; i++) {
        for(int j = 0; j <= l2; j++) {
            for(int k = 0; k <= lv; k++) {
                if(k == 0) {
                    dp[i][j][k] = -12345;
                } else if(i && j) {
                    if(s1[i - 1] == s2[j - 1]) {
                        if(s2[j - 1] != virus[k - 1]) {
                            dp[i][j][k] = dp[i - 1][j - 1][failure[k - 1][s2[j - 1] - 'A']] + 1;
                            dir[i][j][k] = twod;
                        } else {
                            dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                            dir[i][j][k] = threed;
                            if(dp[i][j][k] < dp[i - 1][j][k]) {
                                dp[i][j][k] = dp[i - 1][j][k];
                                dir[i][j][k] = left;
                            }
                            if(dp[i][j][k] < dp[i][j - 1][k]) {
                                dp[i][j][k] = dp[i][j - 1][k];
                                dir[i][j][k] = top;
                            }
                        }
                    } else {
                        if(dp[i - 1][j][k] < dp[i][j - 1][k]) {
                            dp[i][j][k] = dp[i][j - 1][k];
                            dir[i][j][k] = top;
                        } else {
                            dp[i][j][k] = dp[i - 1][j][k];
                            dir[i][j][k] = left;
                        }
                    }
                }
//                printf("%d %d %d %d %d\n", i, j, k, dp[i][j][k], dir[i][j][k]);
            }
        }
    }

    if(dp[l1][l2][lv] <= 0) {
        puts("0");
    } else {
        vector<char> vec;
        int i = l1, j = l2, k = lv;
        while(i && j) {
            switch(dir[i][j][k]) {
            case left: i--; break;
            case top: j--; break;
            case twod: i--; j--; k = failure[k - 1][s2[j] - 'A']; vec.push_back(s1[i]); break;
            case threed: i--; j--; k--; vec.push_back(s1[i]); break;
            }
        }
        reverse(vec.begin(), vec.end());
        vec.push_back('\0');
        puts(&vec[0]);
    }
}