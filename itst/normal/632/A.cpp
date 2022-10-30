#include<bits/stdc++.h>
using namespace std;
string s[41];
int main(){
    long long N , P , num = 0 , ans = 0;
    cin >> N >> P;
    for(int i = 1 ; i <= N ; i++)
        cin >> s[i];
    for(int i = N ; i ; i--){
        num <<= 1;
        if(s[i].size() >= 5 && s[i][4] == 'p')
            ++num;
    }
    while(num){
        ans += (num >> 1) * P;
        if(num & 1)
            ans += P >> 1;
        num >>= 1;
    }
    cout << ans;
    return 0;
}