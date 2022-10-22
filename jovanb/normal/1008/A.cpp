#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool vowel(char x){
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    s += 'z';
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i-1] == 'n') continue;
        if(!vowel(s[i-1]) && !vowel(s[i])){cout << "no"; return 0;}
    }
    cout << "yes";
    return 0;
}