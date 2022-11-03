#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a'){
            cnt++;
        }
    }
    if(cnt * 2 >= s.length()){
        for(int i = 0; i < s.length(); i++){
            if(s[i] < 'a'){
                s[i] += 'a' - 'A';
            }
        }
    }else{
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a'){
                s[i] += 'A' - 'a';
            }
        }
    }
    cout << s;
    return 0;
}