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
    string v[5]={"Danil", "Olya", "Slava", "Ann","Nikita"},s;
    cin>>s;
    long c=0,n=s.length(),i,j,k;
    for(i=0;i<n;++i)
    {
        string temp;
        for(j=i;j<n;++j)
        {
            temp+=s[j];
            for(k=0;k<5;++k)
            if(temp==v[k]) c++;
        }
    }
    if(c==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}