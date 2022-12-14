#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i]; --a[i];
    }
    vector<int> nxt(n), last(n, (int)1e9);
    for(int i = n - 1; i >= 0; --i){
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }
    int A = -1, B = -1, cnt = 0, na = (int)1e9, nb = (int)1e9;
    for(int i = 0; i < n; ++i){
        int x; x = a[i];
        if(x == A){
            cnt += (A != x);
            A = x; na = nxt[i];
        }
        else if(x == B){
            cnt += (B != x);
            B = x; nb = nxt[i];
        }
        else{
            if(na > nb){
                cnt += (A != x);
                A = x; na = nxt[i];
            }
            else{
                cnt += (B != x);
                B = x; nb = nxt[i];
            }
        }
    }
    cout << cnt;
    return 0;
}