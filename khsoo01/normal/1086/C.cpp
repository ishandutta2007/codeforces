#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, x, trf[26], inv[26];
bool vis[26];
char s[N], a[N], b[N];

void solve () {
    scanf("%d%s%s%s",&x,s+1,a+1,b+1);
    n = strlen(s+1);
    for(int i=0;i<x;i++) {
        trf[i] = -1;
        inv[i] = -1;
        vis[i] = 0;
    }
    bool X = false;
    for(int i=1;i<=n;i++) {
        int I = s[i] - 'a', J = a[i] - 'a';
        if(X) {
            if(trf[I] == -1) {
                for(int j=0;j<x;j++) {
                    if(inv[j] == -1) {
                        trf[I] = j;
                        inv[j] = I;
                        break;
                    }
                }
            }
        }
        else if(trf[I] != -1) {
            if(trf[I] >= J) {
                if(trf[I] > J) X = true;
                continue;
            }
            X = true;
            vector<pair<int,int> > V;
            for(int j=1;j<=i;j++) {
                int K = s[j] - 'a';
                if(!vis[trf[K]]) {
                    V.push_back({K, j});
                    vis[trf[K]] = true;
                }
            }
            int C;
            while(!V.empty()) {
                int A, B;
                tie(A, B) = V.back();
                V.pop_back();
                int j;
                for(j=trf[A]+1;j<x;j++) {
                    if(!vis[j]) break;
                }
                if(j == x) {
                    vis[trf[A]] = 0;
                    inv[trf[A]] = -1;
                    trf[A] = -1;
                }
                else {
                    inv[trf[A]] = -1;
                    trf[A] = -1;
                    trf[A] = j;
                    inv[trf[A]] = A;
                    i = B;
                    break;
                }
            }
        }
        else {
            if(inv[J] != -1) {
                for(int j=J+1;j<x;j++) {
                    if(inv[j] == -1) {
                        trf[I] = j;
                        inv[j] = I;
                        X = true;
                        break;
                    }
                }
                if(X) continue;
                X = true;
                vector<pair<int,int> > V;
                for(int j=1;j<i;j++) {
                    int K = s[j] - 'a';
                    if(!vis[trf[K]]) {
                        V.push_back({K, j});
                        vis[trf[K]] = true;
                    }
                }
                int C;
                while(!V.empty()) {
                    int A, B;
                    tie(A, B) = V.back();
                    V.pop_back();
                    int j;
                    for(j=trf[A]+1;j<x;j++) {
                        if(!vis[j]) break;
                    }
                    if(j == x) {
                        vis[trf[A]] = 0;
                        inv[trf[A]] = -1;
                        trf[A] = -1;
                    }
                    else {
                        inv[trf[A]] = -1;
                        trf[A] = -1;
                        trf[A] = j;
                        inv[trf[A]] = A;
                        i = B;
                        break;
                    }
                }
            }
            else {
                trf[I] = J;
                inv[J] = I;
            }
        }
    }
    string S, A, B;
    for(int i=1;i<=n;i++) {
        if(trf[s[i]-'a'] == -1) {
            puts("NO");
            return;
        }
        s[i] = trf[s[i]-'a'] + 'a';
        S += (char)s[i];
        A += (char)a[i];
        B += (char)b[i];
    }
    if(S < A || S > B) {
        puts("NO");
        return;
    }
    puts("YES");
    for(int i=0;i<x;i++) {
        if(trf[i] == -1) {
            for(int j=0;j<x;j++) {
                if(inv[j] != -1) continue;
                trf[i] = j;
                inv[j] = i;
                break;
            }
        }
        putchar(trf[i]+'a');
    }
    puts("");
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--) solve();
}