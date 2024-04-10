#include <cstdio>

using namespace std;

int CC;

int n, m;
char in[55][25];

int hash[(1 << 20)][50];
unsigned char safe[(1 << 20)];

bool bio[1 << 20];
double memo[1 << 20];
double dp(int bit){
       double &r = memo[bit];
       if (bio[bit]++) return r;
       
       int cnt = safe[bit];
       //for (int i = 0; i < n; ++i) if (safe[bit][i]) ++cnt;
       
       if (cnt == n) return 0;
       //printf("A");
       
       double F = (double)(n - cnt) / (double)n;
       int c2 = 0;
       
       for (int i = 0; i < m; ++i){
           if (bit & (1 << i)) continue;
           ++c2;
           r += dp(bit | (1 << i)) + F;
       }
       r /= c2;
       return r;
}

unsigned char M[1 << 25];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", in[i]);
    while (in[0][m] != '\0') ++m;
    
    CC = (1 << m) - 1;
    int xx = 1;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            hash[1 << i][j] = xx * in[j][i];
        }
        xx *= 101;
    }
    for (int i = 0; i <= CC; ++i){
        for (int t = 0; t < n; ++t){
            hash[i][t] = hash[i & -i][t] + hash[i - (i & -i)][t];
        }
    }
    for (int b = 0; b <= CC; ++b){
        for (int i = 0; i < n; ++i) ++M[hash[b][i] & ((1 << 25) - 1)];
        for (int i = 0; i < n; ++i){
            if (M[hash[b][i] & ((1 << 25) - 1)] == 1) ++safe[b];
            M[hash[b][i] & ((1 << 25) - 1)] = 0;
        }
    }
    
    
    
    printf("%.12lf\n", dp(0));
    
    return 0;
}