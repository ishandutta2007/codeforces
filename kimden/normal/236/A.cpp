#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[26]={},ans=0;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]){
            ans++;
        }
    }
    cout << (ans%2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}