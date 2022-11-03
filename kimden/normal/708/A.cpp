#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin >> s;
    bool began=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            if(began){
                break;
            }else{
                if(i==s.length()-1){
                    s[i] = 'z';
                }else
                    continue;
            }
        }else{
            s[i]--;
            began = true;
        }
    }
    cout << s;
    return 0;
}