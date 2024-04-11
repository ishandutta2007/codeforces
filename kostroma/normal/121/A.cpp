#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cstdlib>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<memory.h>
#include<ctime>
#include<cctype>
using namespace std;
 /**
 CAUTION Is int really int?
 *
 Real solution after main function
 */
typedef long long li;
typedef pair <int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
//const long double PI = 3.141592653589793238462643l;
void solve ();
 
int main()
{
        #ifdef _DEBUG
                freopen ("in.txt", "r", stdin);
        #endif
        int t=1;
        //cin>>t;
        while (t--)
    solve();
    return 0;
}

#define int li
bool is_happy (int cur)
{
        while (cur>0)
        {
                if (cur%10!=4 && cur%10!=7)
                        return false;
                cur/=10;
        }
        return true;
}

vector <int> happy;
void solve()
{
        int ll, rr;
        cin>>ll>>rr;
        for (int i=1; i<11; i++)
        for ( int mask=0; mask<(1LL<<i); mask++ )
        {
                int z=0;
                for ( int j=0; j<i; j++ )
                {
                        z*=10;
                        if ( mask & (1<<j) )
                                z+=7;
                        else 
                                z+=4;
                }
                happy.pb (z);
        }
        sort (happy.begin(), happy.end());
        int ans=0;
        bool f=true;
        for (int i=0; i<happy.size(); i++)
                if ( happy[i]>=ll )
                {
                        if (happy[i]<rr)
                        {
                                ans+=(happy[i]-ll+1)*happy[i];
                                ll=happy[i]+1;
                                if (ll>rr)
                                        break;
                        }
                        else 
                        {
                                ans+=(rr-ll+1)*happy[i];
                                break;
                        }
                }
        cout<<ans;
}