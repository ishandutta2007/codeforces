#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
    #define debug(...) \
    fprintf(stderr,__VA_ARGS__)
#else
    #define debug(...) 
#endif
using namespace std;

inline string GetString()
{
    char GS[1000005];
    scanf("%s",GS);string ret=GS;
    return ret;
}

inline char getc()
{
    char c=' ';
    while (c==' ' || c=='\t' || c=='\r' || c=='\n')
        c=getchar();
    return c;
}
//ENDOFTEMPLATE

string s;
vector <int> adj[10005];
vector <int> daftar;
int hasil[10005];
int i,j;
int main()
{
    s = GetString();
    i = 2;
    int numnow = 0;
    while (s[i]!=')') {
        if (s[i]=='_')  {
            ++numnow;
        }
        else {
            if (numnow !=0)
                daftar.pb(numnow);
            numnow = 0;
        }
        ++i;
    }
    if (numnow !=0)
        daftar.pb(numnow);
    i++;
    i++;
    while (s[i]!='.') {
        ++i;
        int num1 = 0;
        int num2 = 0;
        char typ;
        while (s[i]=='_')
        {
            ++i;
            ++num1;
        }
        typ = s[i];
        ++i;
        while (s[i]=='_') {
            ++i;
            ++num2;
        }
        if (typ == '>') {
            adj[num1].pb(num2);
        }
        else {
            adj[num2].pb(num1);
        }
    }
    memset(hasil,-1,sizeof(hasil));
    bool finish;
    while (true) {
        bool update = false;
        for (i=0;i<SZ(daftar);++i) {
            if (hasil[daftar[i]]==-1) {
            //check can assign
                int maxi = -1;
                for (j=0;j<SZ(adj[daftar[i]]);++j) {
                    if (hasil[adj[daftar[i]][j]] < 0)
                        maxi = 1000000;
                    else
                        maxi = max (maxi,hasil[adj[daftar[i]][j]]);
                }
                if (maxi<1000000) {
                    hasil[daftar[i]] = maxi+1;
                    update = true;
                    break;
                }
            }
        }
        finish = true;
        for (i=0;i<SZ(daftar);++i)
            if (hasil[daftar[i]] == -1)
                finish = false;
        if (finish)
            break;
        if (!update)
            break;
    }
    bool valid = finish;
    for (i=0;i<SZ(daftar);++i)
        if (hasil[daftar[i]] <0 || hasil[daftar[i]] > 9)
            valid = false;
    if (!valid)
        printf("false\n");
    else
    {
        for (i=0;i<SZ(daftar);++i)
            printf("%d",hasil[daftar[i]]);
        printf("\n");
    }
}