// Hydro submission #6259225f37de167dd82bd4cd@1650008671381
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;string s;
    cin>>n>>s;
    s='0'+s+'0';
    printf(s.find("000")!=string::npos||s.find("11")!=string::npos?"No\n":"Yes\n");
    return 0;
}