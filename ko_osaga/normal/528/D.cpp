#include <cstdio>
#include <algorithm>
using namespace std;

char mp[255], s1[200005], s2[200050];

int n, m, k;
int psum[4][200050];
bool can[4][200050];
long long nxt[4][200050];
long long bits[4][200050];

int ps(int p, int s, int e){
    s = max(s,0);
    e = min(e,n-1);
    return psum[p][e] - (s ? psum[p][s-1] : 0);
}

bool match(int s){
    int i = 0;
    while (i + 63 < m) {
        for (int j=0; j<4; j++) {
            if(nxt[j][i] & (~bits[j][i+s])) return 0;
        }
        i += 64;
    }
    while (i < m) {
        if(can[mp[s2[i]]][i+s] == 0) return 0;
        i++;
    }
    return 1;
}

int main(){
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
    scanf("%d %d %d %s %s",&n,&m,&k,s1,s2);
    for (int i=0; s1[i]; i++) {
        if(i){
            for (int j=0; j<4; j++) {
                psum[j][i] = psum[j][i-1];
            }
        }
        psum[mp[s1[i]]][i]++;
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<n; j++) {
            if(ps(i,j-k,j+k)) can[i][j] = 1;
        }
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<64; k++) {
                bits[i][j] |= ((1ll * can[i][j+k]) << k);
            }
        }
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<64; k++) {
                nxt[i][j] |= ((1ll * (mp[s2[j+k]] == i)) << k);
            }
        }
    }
    int ret = 0;
    for (int k=0; k<=n-m; k++) {
        if(match(k)) ret++;
    }
    printf("%d",ret);
}