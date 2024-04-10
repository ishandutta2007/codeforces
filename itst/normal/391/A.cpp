#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
    cin >> s;
    int cnt = 0 , sz = 1;
    for(int i = 1 ; i < s.size() ; ++i)
        if(s[i] != s[i - 1]){
            cnt += sz % 2 == 0;
            sz = 1;
        }
        else
            ++sz;
    cnt += sz % 2 == 0;
    cout << cnt;
    return 0;
}