#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100],k,i,br=0;
    cin>>s;
    k=strlen(s);
    for(i=0;i<k;i++){
        if(s[i]=='1')break;
    }
    while(i<k){
        br+=1-(s[i]-'0');
        i++;
    }
    if(br>=6)cout<<"yes";
    else cout<<"no";
    return 0;

}