#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool upcase(char c){
    return c >= 'A' && c <= 'Z';
}

bool downcase(char c){
    return c >= 'a' && c <= 'z';
}

bool num(char c){
    return c >= '0' && c <= '9';
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int down = 0;
    int up = 0;
    int br = 0;
    for(int i=0; i<n; i++){
        if(upcase(s[i])) up++;
        if(downcase(s[i])) down++;
        if(num(s[i])) br++;
    }
    if(br && up && down){cout << s << "\n"; return;}
    for(int i=1; i<=n; i++){
        char c = s[i-1];
        if(upcase(c)) up--;
        if(downcase(c)) down--;
        if(num(c)) br--;
        if(up && down){
            s[i-1] = '0';
            cout << s << "\n";
            return;
        }
        if(up && br){
            s[i-1] = 'a';
            cout << s << "\n";
            return;
        }
        if(br && down){
            s[i-1] = 'A';
            cout << s << "\n";
            return;
        }
        if(upcase(c)) up++;
        if(downcase(c)) down++;
        if(num(c)) br++;
    }
    for(int i=2; i<=n; i++){
        char c = s[i-1];
        char c1 = s[i-2];
        if(upcase(c)) up--;
        if(downcase(c)) down--;
        if(num(c)) br--;
        if(upcase(c1)) up--;
        if(downcase(c1)) down--;
        if(num(c1)) br--;
        if(down){
            s[i-1] = '0';
            s[i-2] = 'A';
            cout << s << "\n";
            return;
        }
        if(up){
            s[i-1] = 'a';
            s[i-2] = '0';
            cout << s << "\n";
            return;
        }
        if(br){
            s[i-1] = 'A';
            s[i-2] = 'a';
            cout << s << "\n";
            return;
        }
        if(upcase(c)) up++;
        if(downcase(c)) down++;
        if(num(c)) br++;
        if(upcase(c1)) up++;
        if(downcase(c1)) down++;
        if(num(c1)) br++;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cerr.tie(0);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}