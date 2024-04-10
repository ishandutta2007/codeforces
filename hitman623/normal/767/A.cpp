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
    long n,x,i,j;
    cin>>n;
    j=n;
    set < long > s;
    set < long > ::iterator it;
    for(i=0;i<n;++i)
    {
        cin>>x;
        s.insert(x);
        it=s.end();
        it--;
        while(*it==j)
        {
            s.erase(it);
            cout<<j<<" ";
            it=s.end();
            j--;
            if(s.size()>0)
            it--;
            else break;
        }
        cout<<endl;
    }
    return 0;
}