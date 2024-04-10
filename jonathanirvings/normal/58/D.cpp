//Codeforces Beta Round 54
//29 Aug 2011

//start of jonathanirvings' template

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
jonathan ganteng banget;

typedef long long LL;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair<int,int> pii;

double EPS = 1e-6;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;

#define DEBUG printf("====TESTING====\n")
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)

//end of jonathanirvings' template

string data[10005];
int n;
char lho;

bool sub(string a,string b)
{
    if (a.length() < b.length()) swap(a,b);
    string s1 = "";
    string s2 = "";
    FOR(i,0,b.length()) s1 = s1 + a[i];
    FOR(i,a.length()-b.length(),b.length()) s2 = s2 + a[i];
    if (s1 == b) return true;
    if (s2 == b) return true;
    return false;
}

bool f(string a,string b)
{
    if (sub(a,b))
    {
        string coba1 = a + lho + b;
        string coba2 = b + lho + a;
        return (coba1 < coba2);
    }
    return (a < b);
}

bool sudah[10005];

int main()
{
    scanf("%d",&n);
    int len = 0;
    FORN(i,1,n)
    {
        getchar();
        cin >> data[i];
        len = len + data[i].length();
    }
    len = len / (n / 2);
    cin >> lho;
    sort(data+1,data+1+n,f);
    int ix = 1;
    while (ix <= n)
    {
        if (!sudah[ix])
        {
            printf("%s%c",data[ix].c_str(),lho);
            sudah[ix] = 1;
            FORN(i,ix+1,n)
            {
                if (!sudah[i] && data[ix].length() + data[i].length() == len)
                {
                    sudah[i] = 1;
                    printf("%s\n",data[i].c_str());
                           break;
                }
            }
        }
        ix++;
    }
    return 0;
}