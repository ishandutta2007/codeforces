#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
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
int n, k;
vector <int> happy;
int fact[20];
int bs (int val)
{
        int l=0, r=happy.size();
        while (l+1<r)
        {
                int m=l+r; m/=2;
                if (happy[m]<=val)
                        l=m;
                else 
                        r=m;
        }
        return l;
}
vector <int> used;
void solve()
{
	cin>>n>>k;
    for (int i=1; i<10; i++)
    for ( int mask=0; mask<(1<<i); mask++ )
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
        if ( k==1 )
        {
                if (n<4)
                {
                        cout<<"0";
                        return;
                }
                int z=bs (n);
                cout<<z+1;
                return;
        }
        int o=1;
        for (int i=1; i<=n; i++)
        {
                o*=i;
                if ( o>1000000000 )
				{
                        o=1000000000;
						break;
				}
        }
        if (o<k)
        {
                cout<<"-1";
                return;
        }
        fact[0]=1;
    for (int i=1; i<=17; i++)
                fact[i]=fact[i-1]*i;
        int u;
        for ( int i=1; i<=16; i++ )
                if ( fact[i]<k && fact[i+1]>=k )
                {
                        u=i;
                        break;
                }
//		cout<<u<<endl;
        int ans=(n-u-1>=4)?(bs(n-u-1)+1):0;
        int beg=n-u;
        used.resize(u+20);
        for ( int curpos=n-u; curpos<=n; curpos++ )
        {
                int z=(k-1)/fact[n-curpos];
                k-=z*fact[n-curpos];
                int t=-1;
                for ( int i=0; i<=u; i++ )
                        if ( !used[i] )
                        {
                                t++;
                                if (t==z)
                                {
                                        used[i]=true;
                                        if ( is_happy(curpos) && is_happy (i+beg) )
                                                ans++;
                                        break;
                                }
                        }
        }
        cout<<ans;
}