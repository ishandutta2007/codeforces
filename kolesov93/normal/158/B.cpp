#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 111;
int s[N], n;
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { 
        int x;
        scanf("%d", &x);
        ++s[x];
    }
        
    ans = s[4];
    s[4] = 0;
    
    ans += s[3];
    if (s[3] > s[1]) s[1] = 0;
    else s[1] -= s[3];
    s[3] = 0;   
    
    ans += s[2] / 2;
    s[2] %= 2;
    
    if (s[2] == 1) {
        ++ans; 
        s[2] = 0;
        if (s[1] < 2) s[1] = 0;
        else s[1] -= 2;
    }
    
    ans += (s[1] + 3) / 4;
    s[1] = 0;
    
    cout << ans << endl;
    
    return 0;
}