#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve();
        return 0;
}
//#define int li
int n, k;
string a[3000][4];
bool gl (char c)
{
        return c=='a' || c=='o' || c=='e' || c=='i' || c=='u';
}
string doing (string q)
{
        int cnt=0;
        for (int i=q.length()-1; i>=0; i--)
                {
                        if (gl(q[i]))
                                cnt++;
                        if (cnt==k)
                        {
                                string ans;
                                for (int j=i; j<q.length(); j++)
                                        ans+=q[j];
                                return ans;
                        }
                }
        cout<<"NO";
        exit(0);
}
int rifm[3000];
void solve ()
{
        cin>>n>>k;
        for ( int i=0; i<n; i++ )
        {
                string q;
                cin>>q;
                string s=doing (q);
                a[i][0]=s;

                cin>>q;
                s=doing (q);
                a[i][1]=s;

                cin>>q;
                s=doing (q);
                a[i][2]=s;

                cin>>q;
                s=doing (q);
                a[i][3]=s;

                if ( a[i][0]==a[i][1] )
                {
                        if (a[i][2]==a[i][3])
                        {
                                if (a[i][0]==a[i][2])
                                        rifm[i]=4;
                                else
                                        rifm[i]=1;
                                continue;
                        }
                        cout<<"NO";
                        return;
                }

                if ( a[i][0]==a[i][2] )
                {
                        if (a[i][1]==a[i][3])
                                rifm[i]=2;
                        else
                        {
                                cout<<"NO";
                                return;
                        }
                        continue;
                }
                if (a[i][0]==a[i][3])
                {
                        if (a[i][1]==a[i][2])
                                rifm[i]=3;
                        else
                        {
                                cout<<"NO";
                                return;
                        }
                        continue;
                }
                cout<<"NO";
                return;
        }

        int cur=rifm[0];
        for (int i=1; i<n; i++)
        {
                int now=rifm[i];
                if ( now==4 )
                        continue;
                if ( cur==4 )
                {
                        cur=now;
                        continue;
                }
                if ( now!=cur )
                {
                        cout<<"NO";
                        return;
                }
        }

        if (cur==4)
                cout<<"aaaa";
        if (cur==1)
                cout<<"aabb";
        if (cur==2)
                cout<<"abab";
        if (cur==3)
                cout<<"abba";
}