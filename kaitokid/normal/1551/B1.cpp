#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[29];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {

        string s;
        cin>>s;
        for(int i=0;i<28;i++)fr[i]=0;
        int f1=0,f2=0;
        for(int i=0;i<s.size();i++)
        {
            fr[s[i]-'a']++;
            if(fr[s[i]-'a']==1)f1++;
            if(fr[s[i]-'a']==2){f1--;f2++;}
        }
        cout<< f2 + (f1/2)<<endl;

    }
    return 0;
}