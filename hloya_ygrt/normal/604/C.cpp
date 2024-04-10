#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <deque>

#include <list>
#include <stdio.h>
#include <string>
#include <vector>


#define mp make_pair
#define f first

#define pb push_back



using namespace std;
string s;
int main()
{
   int n;
   int ans=1;
   pair<int,bool> maxne=mp(0,0);
   //scanf("%d",&n);
   cin>>n;
   cin>>s;

    int cur=s[0],r=0;
    for(int i=1;i<s.size();i++)
    {
        if (s[i]!=cur)
        {
            ans++;
            if (maxne.f<r)
            {
                bool se=0;
                    if (r==1&&i==s.size()-1)
                    se++;
                maxne=mp(r,se);
            }
            cur=s[i];
            r=0;
        }
        else
        {
            r++;
        }
    }

    if (r!=0)
    {
        // ans++;
            if (maxne.f<r)
            {
                bool se=0;
                    if (r==1)
                    se++;
                maxne=mp(r,se);
            }

            r=0;
    }
    if (maxne.f!=0)
        ans+=2;


    if (s.size()<ans)
        ans=s.size();
    cout<<ans;
    return 0;
}