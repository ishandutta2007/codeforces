#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i] != '+'){
            v.push_back(s[i]-'1'+1);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i){
            cout << '+';
        }
        cout << v[i];
    }
}