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
long a,b,f,k;

int main()
{
    io
    cin>>a>>b>>f>>k;
    if(b<f || (2*(a-f)>b && k>1) || (a-f)>b || (k>2 && 2*f>b)) {cout<<-1;exit(0);}
    long i,cur=b-f,cnt=0;
    for(i=1;i<=k/2;++i)
    {
        if(2*(a-f)>cur)
        {
            cnt++;
            cur=b-2*(a-f);
        }
        else cur-=2*(a-f);
        if(i<=k/2-1 || k%2)
        {
            if(cur>=2*f)
            cur-=2*f;
            else
            {
                cnt++;
                cur=b-2*f;
            }
        }
        else
        {
            if(cur<f)
            cnt++;
        }
    }
    if(k%2)
    {
        if(cur<a-f)
        cnt++;
    }
    cout<<cnt;
    return 0;
}