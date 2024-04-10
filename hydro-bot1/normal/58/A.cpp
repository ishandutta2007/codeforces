// Hydro submission #63455ee055979fe860410a38@1665490656907
#include <bits/stdc++.h>
using namespace std;
int main(){
    char c[5] = {'h','e','l','l','o'};
    string s;
    cin>>s;
    int len = s.length();
    int t = 0;
    for(int i = 0;i < 5;i++){
        bool flag = 1;
        for(int j = t;j < len;j++){
            if(c[i] == s[j]){
                flag = 0;
                t = j + 1;
                break;
            }
        }
        if(flag){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}