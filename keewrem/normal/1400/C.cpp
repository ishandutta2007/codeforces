#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll N,T,K;


int main(){
    cin >> T;
    string s;
    while(T--){
        cin >> s;
        N = s.size();
        cin >> K;
        string r(N,'1');
        for(int i = 0; i < N; i++){
            if(i+K < N && s[i+K]=='0')r[i] = '0';
            if(i-K >= 0 && s[i-K]=='0')r[i] = '0';
        }
        string pr(N,'0');
        for(int i = 0; i < N; i++){
            if(i+K < N && r[i+K]=='1')pr[i] = '1';
            if(i-K >= 0 && r[i-K]=='1')pr[i] = '1';
        }
        if(pr == s)cout << r <<"\n";
        else cout << "-1\n";
    }
    return 0;
}