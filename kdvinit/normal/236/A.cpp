/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int n=s.size();

    int freq[26]={0};
    for(int i=0;i<n;i++)
    {
        int x=s[i]-97;
        freq[x]=1;
    }

    int ans=0;
    for(int i=0;i<26;i++)
    {
        ans+=freq[i];
    }

    if(ans%2==0) cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;

    return 0;
}