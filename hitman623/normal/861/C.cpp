#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    string s;
    long i,n,c=0,cur=-1,cc=0;
    cin>>s;
    n=s.length();
    for(i=0;i<n;++i)
    {
        if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u')
        {
            cout<<s[i];
            c=0;
            cc=0;
            cur=-1;
        }
        else
        {
            c++;
            cc++;
            if(c>=2 && cc>=3) {cout<<" ";c=1;cc=1;}
            cur=s[i];
            cout<<s[i];
            i++;
            while(s[i]==cur) {cc++;if(c>=2 && cc>=3) {cout<<" ";c=1;cc=1;} cout<<s[i];i++;}
            i--;
        }
    }
    return 0;
}