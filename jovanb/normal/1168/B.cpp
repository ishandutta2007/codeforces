#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    string s;
    cin >> s;
    int n = s.size();
    ll cnt = 0;
    for(int len=1; len<=8; len++){
        for(int l=0; l+len-1<n; l++){
            int r = l+len-1;
            bool d = 0;
            for(int x=l; x<=r; x++){
                for(int k=1; x+2*k<=r; k++){
                    if(s[x] == s[x+k] && s[x+k] == s[x+2*k]) d = 1;
                }
            }
            cnt += d;
        }
    }
    for(int len=9; len<=n; len++){
        cnt += n-len+1;
    }
    cout << cnt;
    return 0;
}