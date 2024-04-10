#include <bits/stdc++.h>
using namespace std;
#define int long long
string s,s1;
char c,c1;
int tmp = 0,ii = 0,ans = 0,ansi = 0;
signed main(){
    int n;
    cin >> n;
    ans++;
    map<int,int> b;
    b[n]++;
    int x = 1;
    while(true){
        n++;
        while(n % 10 == 0){
            n /= 10;
        }
        if (b.find(n) == b.end()){
            ans++;
            b[n]++;
        }
        else{
            cout << ans;
            return 0;
        }
    }
    cout << ans;

}