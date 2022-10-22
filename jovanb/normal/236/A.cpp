#include <bits/stdc++.h>

using namespace std;
int post[26];
char str[100];
int main()
{
    cin>>str;
    int k=strlen(str),i,br=0;
    for(i=0;i<k;i++){
        post[str[i]-97]=1;
    }
    for(i=0;i<26;i++){
        br+=post[i];
    }
    if(br%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    return 0;
}