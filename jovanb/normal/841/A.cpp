#include <bits/stdc++.h>

using namespace std;
int baloni[200];
int main()
{
    int n,m,i;
    char str[200];

    cin>>n>>m;
    cin>>str;
    int k=strlen(str);
    for(i=0;i<k;i++){
        baloni[str[i]-'A']++;

    }
    for(i=0;i<26;i++){
        baloni[i]=baloni[i+32];
    }
    for(i=0;i<26;i++){
        if(baloni[i]>m){cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
    return 0;
}