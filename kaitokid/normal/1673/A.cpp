#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int sum=0;
        for(int i=0;i<s.size();i++)sum+=(s[i]-'a'+1);
        int n=s.size();
        if((n%2)==0){cout<<"Alice "<<sum<<endl;continue;}
        int u=min((s[0]-'a'),(s[n-1]-'a'))+1;
        sum-=u;
        if(sum>u){cout<<"Alice "<<sum-u<<endl;continue;}
        if(u>sum){cout<<"Bob "<<u-sum<<endl;continue;}


    }
    return 0;
}