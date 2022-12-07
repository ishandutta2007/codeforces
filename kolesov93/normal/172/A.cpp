#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char w[2][33];
int ans, n;

int main() {
    scanf("%d", &n);
    
    scanf("%s", w[0]);
    ans = strlen(w[0]);
    
    for (int i = 1; i < n; ++i) {
        int c = i & 1;
        int d = 1 - c;
        scanf("%s", w[c]);
        
        for (int j = 0; j < ans; ++j) {
            if (w[c][j] != w[d][j]) {
                ans = j;
                break;
            }
        }
    }
    
    cout << ans << endl;
        
    return 0;
}