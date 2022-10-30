#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[8][3];
int c[8][4];

long long dist(int x1, int x2, int y1, int y2, int z1, int z2)
{
    return (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2) + (long long)(z1 - z2) * (z1 - z2);
}

int main()
{
    int i, j, k, l, r;
    vector <int> v;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    
    do {
        for (i = 1; i < 8; i++) {
            vector <int> w;
            
            w.push_back(0);
            w.push_back(1);
            w.push_back(2);
            
            do {
                long long x = dist(a[0][v[0]], a[i][w[0]], a[0][v[1]], a[i][w[1]], a[0][v[2]], a[i][w[2]]);
                
                if (x == 0) continue;
                
                for (j = 1; j < 8; j++) {
                    vector <int> z;
                    
                    if (i == j) continue;
                    
                    z.push_back(0);
                    z.push_back(1);
                    z.push_back(2);
                    
                    do {
                        if (dist(a[i][w[0]], a[j][z[0]], a[i][w[1]], a[j][z[1]], a[i][w[2]], a[j][z[2]]) != x * 2) break;
                        if (dist(a[0][v[0]], a[j][z[0]], a[0][v[1]], a[j][z[1]], a[0][v[2]], a[j][z[2]]) != x * 3) break;
                        
                        for (k = 0; k < 8; k++) c[k][0] = -1;
                        
                        c[0][0] = 0;
                        c[0][1] = v[0];
                        c[0][2] = v[1];
                        c[0][3] = v[2];
                        c[1][0] = i;
                        c[1][1] = w[0];
                        c[1][2] = w[1];
                        c[1][3] = w[2];
                        c[7][0] = j;
                        c[7][1] = z[0];
                        c[7][2] = z[1];
                        c[7][3] = z[2];
                        
                        for (k = 1; k < 8; k++) {
                            if (k == i || k == j) continue;
                            
                            for (l = 0; l < 8; l++) {
                                int f = 0;
                                vector <int> z2;
                                
                                if (c[l][0] != -1) continue;
                                
                                z2.push_back(0);
                                z2.push_back(1);
                                z2.push_back(2);
                                
                                do {
                                    for (r = 0; r < 8; r++) {
                                        if (c[r][0] == -1) continue;
                                        
                                        if (dist(a[k][z2[0]], a[c[r][0]][c[r][1]], a[k][z2[1]], a[c[r][0]][c[r][2]], a[k][z2[2]], a[c[r][0]][c[r][3]]) != x * __builtin_popcount(l ^ r)) break;
                                    }
                                    
                                    if (r == 8) {
                                        f = 1;
                                        
                                        c[l][0] = k;
                                        c[l][1] = z2[0];
                                        c[l][2] = z2[1];
                                        c[l][3] = z2[2];
                                        
                                        break;
                                    }
                                } while (next_permutation(z2.begin(), z2.end()));
                                
                                if (f == 1) break;
                            }
                            
                            if (l == 8) break;
                        }
                        
                        if (k == 8) {
                            puts("YES");
                            
                            for (l = 0; l < 8; l++) {
                                for (r = 0; r < 8; r++) {
                                    if (c[r][0] == l) {
                                        printf("%d %d %d\n", a[l][c[r][1]], a[l][c[r][2]], a[l][c[r][3]]);
                                    }
                                }
                            }
                            
                            return 0;
                        }
                    } while (next_permutation(z.begin(), z.end()));
                }
            } while (next_permutation(w.begin(), w.end()));
        }
    } while (next_permutation(v.begin(), v.end()));
    
    puts("NO");
    
    return 0;
}