#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char getDiff(char a, char b){
    bool aa = (a == 'a' || b == 'a');
    bool xx = (a == 'x' || b == 'x');
    bool zz = (a == 'z' || b == 'z');
    if(!aa){
        return 'a';
    }
    if(!xx){
        return 'x';
    }
    if(!zz){
        return 'z';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    k = n - k;
    string s, t, u(n, '?');
    cin >> s >> t;
    int z = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != t[i]){
            ++z;
        }
    }
   // cout << k << " " << n << " " << z << endl;
    if(k > z / 2 + n - z){
        cout << -1 << endl;
        return 0;
    }
    int a, b;
    if(k >= n - z){
        a = k - (n - z);
        b = n - z;
    }else{
        a = 0;
        b = k;
    }
    a *= 2;
    for(int i = 0; i < n; ++i){
        if(s[i] == t[i]){
            if(b > 0){
                --b;
                u[i] = s[i];
            }else{
                u[i] = getDiff(s[i], t[i]);
            }
        }else{
            if(a > 0){
                if(a % 2){
                    u[i] = s[i];
                }else{
                    u[i] = t[i];
                }
                --a;
            }else{
                u[i] = getDiff(s[i], t[i]);
            }
        }
    }
    cout << u << endl;


}