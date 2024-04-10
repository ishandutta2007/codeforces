#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int res[300005];


bool solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0; i<k; i++) res[i] = -1;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            if(res[i%k] == 1) return 0;
            res[i%k] = 0;
        }
        else if(s[i] == '1'){
            if(res[i%k] == 0) return 0;
            res[i%k] = 1;
        }
    }
    int a = 0, b = 0;
    for(int i=0; i<k; i++){
        if(res[i] == 0) a++;
        else if(res[i] == 1) b++;
    }
    //cout << a << " " << s << " " << b << endl;
    k -= a+b;
    return (abs(b-a) <= k);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}