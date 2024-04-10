#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int a,b,ans=0;
    bool flag=true;
    string s,s1;
    cin >> s >> s1;
    a=s.size();
    b=s1.size();
    if (a<b){
        a=b;
        b=s.size();
        flag=false;
    }
    for(int i=b-1;i>=0;--i){
        if (flag){
            if (s1[i]==s[i+a-b]){
                ans++;
            }
            else{
                break;
            }
        }
        if (! flag){
            if (s[i]==s1[i+a-b]){
                ans++;
            }
            else{
                break;
            }
        }
    }
    cout << (a+b-2*ans);

}