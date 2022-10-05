#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, K = 30;

char s[N], a[N], b[N], r[K], rr[K];
int n, k, c, u[K], uu[K];

int f(int x){
    for(int i = 0; i < k; i++){ rr[i] = r[i]; uu[i] = u[i]; }
    if(!r[s[x] - 'a']){
        if(u[a[x] - 'a']) return 0;
        r[s[x] - 'a'] = a[x];
        u[a[x] - 'a'] = 1;
    }
    else if(r[s[x] - 'a'] != a[x]) return 0;
    for(int i = x + 1; i < n; i++){
        if(!r[s[i] - 'a']){
            for(char t = a[i] + 1; t < 'a' + k; t++){
                if(!u[t - 'a']){
                    r[s[i] - 'a'] = t;
                    u[t - 'a'] = 1;
                    return 1;
                }
            }
            if(u[a[i] - 'a']) return 0;
            r[s[i] - 'a'] = a[i];
            u[a[i] - 'a'] = 1;
            continue;
        }
        if(r[s[i] - 'a'] == a[i]) continue;
        return (r[s[i] - 'a'] > a[i]);
    }
    return 1;
}

int g(int x){
    for(int i = 0; i < k; i++){ rr[i] = r[i]; uu[i] = u[i]; }
    if(!r[s[x] - 'a']){
        if(u[b[x] - 'a']) return 0;
        r[s[x] - 'a'] = b[x];
        u[b[x] - 'a'] = 1;
    }
    else if(r[s[x] - 'a'] != b[x]) return 0;
    for(int i = x + 1; i < n; i++){
        if(!r[s[i] - 'a']){
            for(char t = b[i] - 1; t >= 'a'; t--){
                if(!u[t - 'a']){
                    r[s[i] - 'a'] = t;
                    u[t - 'a'] = 1;
                    return 1;
                }
            }
            if(u[b[i] - 'a']) return 0;
            r[s[i] - 'a'] = b[i];
            u[b[i] - 'a'] = 1;
            continue;
        }
        if(r[s[i] - 'a'] == b[i]) continue;
        return (r[s[i] - 'a'] < b[i]);
    }
    return 1;
}

int main(){
    int tc; scanf("%d", &tc); while(tc--){
        scanf("%d%s%s%s", &k, s, a, b);
        n = strlen(s);
        fill(r, r + k + 1, 0);
        fill(u, u + k, 0);
        c = 1;
        for(int i = 0; i < n; i++){
            if(a[i] < b[i]){
                int d = 0;
                for(char j = a[i] + 1; j < b[i]; j++){
                    if(!r[s[i] - 'a'] || r[s[i] - 'a'] == j){
                        if(!r[s[i] - 'a'] && u[j - 'a']) continue;
                        r[s[i] - 'a'] = j;
                        u[j - 'a'] = 1;
                        d = 1;
                        break;
                    }
                }
                if(d) break;
                if(f(i)) break;
                for(int j = 0; j < k; j++){ r[j] = rr[j]; u[j] = uu[j]; }
                if(g(i)) break;
                c = 0;
                break;
            }
            else{
                if(r[s[i] - 'a'] && r[s[i] - 'a'] != a[i]){ c = 0; break; }
                if(!r[s[i] - 'a'] && u[a[i] - 'a']){ c = 0; break; }
                r[s[i] - 'a'] = a[i];
                u[a[i] - 'a'] = 1;
            }
        }
        if(c){
            for(int i = 0, j = 0; i < k; i++) if(!u[i]) u[j++] = i;
            for(int i = 0, j = 0; i < k; i++) if(!r[i]) r[i] = u[j++] + 'a'; 
            puts("YES"); puts(r);
        }
        else puts("NO");
    }
}