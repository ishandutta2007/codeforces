#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int mx=1,cur=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            cur++;
            mx = max(cur, mx);
            if(mx>=7){
                cout << "YES";
                return 0;
            }
        }else{
            cur = 1;
        }
    }
    cout << "NO";
    return 0;
}