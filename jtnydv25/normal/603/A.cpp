#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt1 = 0,cnt2 = 0;
 
    for(int i = 0;i<s.length()-1;i++){
        if(s[i] != s[i+1])
            cnt1++;
        else
            cnt2++;
    }
    cout<<cnt1 + 1 + min(2,cnt2) ;

}