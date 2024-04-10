#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        string s;
        cin >> s;
        s = '$' + s + '$';

        bool flag = 1;
        for(int i=1; i<s.size()-1; i++){
            if( s[i] == s[i+1] && s[i] != '?' ) flag = 0;
            if( s[i] == '?' ){
                if( s[i-1] != 'a' && s[i+1] != 'a' ){
                    s[i] = 'a'; continue;
                }
                if( s[i-1] != 'b' && s[i+1] != 'b' ){
                    s[i] = 'b'; continue;
                }
                if( s[i-1] != 'c' && s[i+1] != 'c' ){
                    s[i] = 'c'; continue;
                }
            }
        }

        if( !flag ) cout << -1 << '\n';
            else{
                for(int i=1; i<s.size()-1; i++)
                    cout << s[i];
                cout << '\n';
            }
    }

    return 0;
}