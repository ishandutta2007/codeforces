#include <bits\stdc++.h>

const int maxn=2e5;
const int inf=2e9;
const int eps=1e-9;
const int mod=1e9+7;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long
#define ld long double

#define forn() for(int i=0;i<n;i++)
#define nfor() for(int i=n-1;i>=0;i--)

using namespace std;

int pref0[maxn],pref1[maxn];

int main()
{
    string a,b;
    cin>>a>>b;

    int sum=0;
    for (int i=0;i<b.size();i++)
    {

        if (b[i]=='0')
        {

            sum++;

        }   pref0[i]=sum;

    }
    sum=0;
    for (int i=0;i<b.size();i++)
    {

        if (b[i]=='1')
        {
            sum++;

        } pref1[i]=sum;

    }
    ll ans=0;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]=='0')
        {
            if (i>0)
            ans+=pref1[b.size()-a.size()+i]-pref1[i-1];
            else
            ans+=pref1[b.size()-a.size()];
        }
        else
        {
            if (i>0)
            ans+=pref0[b.size()-a.size()+i]-pref0[i-1];
            else
            ans+=pref0[b.size()-a.size()];
        }
    }
    cout<<ans;
  //  cout << "Hello world!" << endl;
    return 0;
}