#include <cstdio>

using namespace std;

int k, x, n, m;

int main(){
    scanf("%d%d%d%d", &k, &x, &n, &m);
    for (int a1 = 0; a1 <= n / 2; ++a1){
        for (int a2 = 0; a2 <= 2; ++a2){
            for (int a3 = 0; a3 <= 2; ++a3){
                if (n / 2 == a1){
                   if (n % 2 == 0 && (a2 != 0 || a3 != 2)) continue;
                   if (n % 2 == 1 && a2 != 0 && a3 != 2) continue;
                }
                for (int b1 = 0; b1 <= m / 2; ++b1){
                    for (int b2 = 0; b2 <= 2; ++b2){
                        for (int b3 = 0; b3 <= 2; ++b3){
                            if (m / 2 == b1){
                               if (m % 2 == 0 && (b2 != 0 || b3 != 2)) continue;
                               if (m % 2 == 1 && b2 != 0 && b3 != 2) continue;
                            }
                            
                            int aa1 = a1, aa2 = a2, aa3 = a3, bb1 = b1, bb2 = b2, bb3 = b3, cc1, cc2, cc3;
                            for (int i = 1; i != k; ++i){
                                cc1 = aa1 + bb1;
                                if (aa3 == 0 && bb2 == 2) ++cc1;
                                cc2 = aa2;
                                cc3 = bb3;
                                
                                aa1 = bb1;
                                aa2 = bb2;
                                aa3 = bb3;
                                
                                bb1 = cc1;
                                bb2 = cc2;
                                bb3 = cc3;
                                
                                if (aa1 > x) break;
                            }
                            
                            if (aa1 == x){
                               
                               int cnt = 0;
                               if (a2 != 0){printf("%c", 'A' + a2); ++cnt;}
                               for (int i = 0; i < a1; ++i){printf("AC"); cnt += 2;}
                               if (cnt != n){
                                  while (cnt != n - 1){printf("B"); ++cnt;}
                                  printf("%c", 'A' + a3);
                               }
                               printf("\n");
                               
                               cnt = 0;
                               if (b2 != 0){printf("%c", 'A' + b2); ++cnt;}
                               for (int i = 0; i < b1; ++i){printf("AC"); cnt += 2;}
                               if (cnt != m){
                                  while (cnt != m - 1){printf("B"); ++cnt;}
                                  printf("%c", 'A' + b3);
                               }
                               printf("\n");
                               
                               return 0;
                            }
                            
                        }
                    }
                }
            }
        }
    }
    printf("Happy new year!\n");
    return 0;
}