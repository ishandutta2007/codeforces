#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 105;

char s[N];
int n, t[N];

int main(){
    int tc; scanf("%d", &tc); for(; tc--; ){
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++){
            if('a' <= s[i] && s[i] <= 'z') t[i] = 1;
            else if('A' <= s[i] && s[i] <= 'Z') t[i] = 2;
            else t[i] = 3;
        }
        if(count(t, t + n, t[0]) == n){
            if(t[0] == 1){ s[1] = 'A'; s[2] = '1'; }
            else if(t[0] == 2){ s[1] = 'a'; s[2] = '1'; }
            else{ s[1] = 'A'; s[2] = 'a'; }
            puts(s);
            continue;
        }
        else if(count(t, t + n, 1) == 0 || count(t, t + n, 2) == 0 ||
            count(t, t + n, 3) == 0){
            int x, y, z;
            char c;
            if(count(t, t + n, 1) == 0){ x = 1; c = 'a'; y = 2; z = 3; }
            if(count(t, t + n, 2) == 0){ x = 2; c = 'A'; y = 1; z = 3; }
            if(count(t, t + n, 3) == 0){ x = 3; c = '1'; y = 2; z = 1; }
            if(count(t, t + n, y) > 1){
                for(int i = 0; i < n; i++) if(t[i] == y){ s[i] = c; break; }
                puts(s);
            }
            else{
                for(int i = 0; i < n; i++) if(t[i] == z){ s[i] = c; break; }
                puts(s);
            }
        }
        else puts(s);
    } 
}