#include <cstdio>
#include <string>
#include <map>

using namespace std;

char s[10000];
char ans1[1001];
char ans2[1001];
int a[5001][1000];

int main() {
    int n, m, i, j, k;
    map <string, int> mp;
    
    scanf("%d %d%*c", &n, &m);
    
    mp["?"] = n;
    for (i = 0; i < m; i++) a[n][i] = 2;
    
    for (i = 0; i < n; i++) {
        string var = "";
        
        fgets(s, 10000, stdin);
        
        for (j = 0; ; j++) {
            if (s[j] == ' ') break;
            var += s[j];
        }
        
        mp[var] = i;
        
        j += 4;
        
        if (s[j] == '0' || s[j] == '1') {
            for (k = 0; k < m; j++, k++) a[i][k] = s[j] - '0';
        } else {
            int x, y;
            string var1 = "", var2 = "", op = "";
            
            for (; ; j++) {
                if (s[j] == ' ') break;
                var1 += s[j];
            }
            
            for (j++; ; j++) {
                if (s[j] == ' ') break;
                op += s[j];
            }
            
            for (j++; s[j] != '\n'; j++) {
                var2 += s[j];
            }
            
            x = mp[var1];
            y = mp[var2];
            
            if (op == "AND") {
                for (j = 0; j < m; j++) {
                    if (a[x][j] == 0 || a[y][j] == 0 || a[x][j] + a[y][j] == 5) {
                        a[i][j] = 0;
                    } else if (a[x][j] == 1 && a[y][j] == 1) {
                        a[i][j] = 1;
                    } else if (a[x][j] == 2 || a[y][j] == 2) {
                        a[i][j] = 2;
                    } else {
                        a[i][j] = 3;
                    }
                }
            } else if (op == "OR") {
                for (j = 0; j < m; j++) {
                    if (a[x][j] == 1 || a[y][j] == 1 || a[x][j] + a[y][j] == 5) {
                        a[i][j] = 1;
                    } else if (a[x][j] == 0 && a[y][j] == 0) {
                        a[i][j] = 0;
                    } else if (a[x][j] == 2 || a[y][j] == 2) {
                        a[i][j] = 2;
                    } else {
                        a[i][j] = 3;
                    }
                }
            } else {
                for (j = 0; j < m; j++) {
                    if (a[x][j] == a[y][j]) {
                        a[i][j] = 0;
                    } else if (a[x][j] + a[y][j] == 1 || a[x][j] + a[y][j] == 5) {
                        a[i][j] = 1;
                    } else if (a[x][j] == 0) {
                        a[i][j] = a[y][j];
                    } else if (a[y][j] == 0) {
                        a[i][j] = a[x][j];
                    } else if (a[x][j] == 1) {
                        a[i][j] = 5 - a[y][j];
                    } else {
                        a[i][j] = 5 - a[x][j];
                    }
                }
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int c1 = 0, c2 = 0;
        
        for (j = 0; j < n; j++) {
            if (a[j][i] == 2) {
                c1++;
            } else if (a[j][i] == 3) {
                c2++;
            }
        }
        
        if (c1 == c2) {
            ans1[i] = ans2[i] = '0';
        } else if (c1 < c2) {
            ans1[i] = '1';
            ans2[i] = '0';
        } else {
            ans1[i] = '0';
            ans2[i] = '1';
        }
    }
    
    printf("%s\n", ans1);
    printf("%s\n", ans2);
    
    return 0;
}