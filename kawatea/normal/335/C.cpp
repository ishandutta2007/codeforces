#include <cstdio>
#include <set>

using namespace std;

int b[3][101];

int grundy(int x, int y)
{
    int i, j;
    set <int> s;
    
    if (b[x][y] != -1) return b[x][y];
    
    for (i = 0; i < y; i++) {
        for (j = 0; j < 2; j++) {
            int g = 0;
            
            if (x == 0) {
                if (i == y - 1 && j == 1) continue;
                
                if (i == 1) {
                    g ^= 1;
                } else if (i > 1) {
                    g ^= grundy(0, i);
                }
                
                if (j == 0) {
                    if (i == y - 2) {
                        g ^= 1;
                    } else if (i < y - 3) {
                        g ^= grundy(2, y - i - 1);
                    }
                } else {
                    if (i == y - 3) {
                        g ^= 1;
                    } else if (i < y - 3) {
                        g ^= grundy(1, y - i - 1);
                    }
                }
            } else if (x == 1) {
                if (j == 1) continue;
                if (i == y - 1) continue;
                
                if (i == 1) {
                    g ^= 1;
                } else if (i > 2) {
                    g ^= grundy(2, i);
                }
                
                if (i == y - 3) {
                    g ^= 1;
                } else if (i < y - 3) {
                    g ^= grundy(1, y - i - 1);
                }
            } else if (x == 2) {
                if (i == 0 && j == 1) continue;
                if (i == y - 1 && j == 1) continue;
                
                if (j == 0) {
                    if (i == 1) {
                        g ^= 1;
                    } else if (i > 2) {
                        g ^= grundy(2, i);
                    }
                    
                    if (i == y - 2) {
                        g ^= 1;
                    } else if (i < y - 3) {
                        g ^= grundy(2, y - i - 1);
                    }
                } else {
                    if (i == 2) {
                        g ^= 1;
                    } else if (i > 2) {
                        g ^= grundy(1, i);
                    }
                    
                    if (i == y - 3) {
                        g ^= 1;
                    } else if (i < y - 3) {
                        g ^= grundy(1, y - i - 1);
                    }
                }
            }
            
            s.insert(g);
        }
    }
    
    for (i = 0; ; i++) {
        if (s.count(i) == 0) return b[x][y] = i;
    }
}

int main()
{
    int r, n, g = 0, i, j, k;
    int a[100][2] = {0};
    
    scanf("%d %d", &r, &n);
    
    if (n == 0) {
        if (r % 2 == 1) {
            puts("WIN");
        } else {
            puts("LOSE");
        }
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        a[x][y] = 1;
        a[x][1 - y] = 1;
        
        if (x > 0) a[x - 1][1 - y] = 1;
        if (x < r - 1) a[x + 1][1 - y] = 1;
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j <= r; j++) {
            b[i][j] = -1;
        }
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < 2; j++) {
            if (a[i][j] == 1) continue;
            
            if (j == 0) {
                if (a[i][1] == 0) {
                    for (k = i + 1; k < r; k++) {
                        if (a[k][0] == 1 || a[k][1] == 1) break;
                    }
                    
                    g ^= grundy(0, k - i + 1);
                    
                    i = k;
                    
                    break;
                } else {
                    if (i == r - 1 || a[i + 1][0] == 1) {
                        g ^= 1;
                        
                        i++;
                        
                        break;
                    } else if (a[i + 1][1] == 1) {
                        i++;
                        
                        break;
                    } else {
                        for (k = i + 1; k < r; k++) {
                            if (a[k][0] == 1) {
                                g ^= grundy(1, k - i + 1);
                                
                                break;
                            } else if (a[k][1] == 1) {
                                g ^= grundy(2, k - i + 1);
                                
                                break;
                            }
                        }
                        
                        if (k == r) g ^= grundy(0, k - i);
                        
                        i = k;
                        
                        break;
                    }
                }
            } else {
                if (i == r - 1 || a[i + 1][1] == 1) {
                    g ^= 1;
                    
                    i++;
                    
                    break;
                } else if (a[i + 1][0] == 1) {
                    i++;
                    
                    break;
                } else {
                    for (k = i + 1; k < r; k++) {
                        if (a[k][0] == 1) {
                            g ^= grundy(2, k - i + 1);
                            
                            break;
                        } else if (a[k][1] == 1) {
                            g ^= grundy(1, k - i + 1);
                            
                            break;
                        }
                    }
                    
                    if (k == r) g ^= grundy(0, k - i);
                    
                    i = k;
                    
                    break;
                }
            }
        }
    }
    
    if (g == 0) {
        puts("LOSE");
    } else {
        puts("WIN");
    }
    
    return 0;
}