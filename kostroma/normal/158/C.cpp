#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();

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

vector <string> now;

void solve ()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        string qq;  cin>>qq;
        if (qq=="cd")
        {
        string cur; cin>>cur;
        if (cur[0]=='/')
        {
            now.resize(0);
            string a;
            for (int j=1; j<cur.size(); j++)
            {
                if (cur[j]=='/')
                {
                    if (a=="..")
                        now.resize(now.size()-1);
                    else
                        now.pb(a);
                    a.resize(0);
                }
                else
                    a.pb(cur[j]);
            }
            if (a.size()>0)
            {
                if (a=="..")
                        now.resize(now.size()-1);
                    else
                        now.pb(a);
            }
        }
        else
        {
            string a;
            for (int j=0; j<cur.size(); j++)
            {
                if (cur[j]=='/')
                {
                    if (a=="..")
                        now.resize(now.size()-1);
                    else
                        now.pb(a);
                    a.resize(0);
                }
                else
                    a.pb(cur[j]);

            }
            if (a.size()>0)
            {
                if (a=="..")
                        now.resize(now.size()-1);
                    else
                        now.pb(a);
            }
        }
        }
        else
        {
            cout<<"/";
            for (int i=0; i<now.size(); i++)
                cout<<now[i]<<"/";
            cout<<endl;
        }
    }
}