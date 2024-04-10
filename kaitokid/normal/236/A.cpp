#include <bits/stdc++.h>

using namespace std;
int a[200];
int main()
{string s;
cin>>s;
int y=0;
for(int i=0;i<s.size();i++)
{a[(int)s[i]]++;
if(a[(int)s[i]]==1){y++;}

}

if(y%2==0){cout<<"CHAT WITH HER!";}
else{cout<<"IGNORE HIM!";}
    return 0;
}