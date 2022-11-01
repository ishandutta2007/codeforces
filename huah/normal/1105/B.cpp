#include<bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
    string s;
    int n,k;
    cin>>n>>k;
    cin>>s;
    char t=s[0];
    int cot=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t) cot++;
        else
        {
            a[t-'a']+=cot/k;
            t=s[i],cot=1;
        }
    }
    a[t-'a']+=cot/k;
    int ans=0;
    for(int i=0;i<26;i++) ans=max(ans,a[i]);
    printf("%d\n",ans);
}