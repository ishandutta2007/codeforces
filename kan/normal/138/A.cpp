#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int maxn=10005;

char s1[maxn],s2[maxn],s3[maxn],s4[maxn];
int n,k;

void bad()
{
    cout << "NO" << endl;
    exit(0);
}

bool eq(char * s1,char * s2)
{
    int n1=strlen(s1);
    int n2=strlen(s2);
    int kg=0;
    while (n1>0 && n2>0 && kg<k)
    {
        if (s1[n1-1]!=s2[n2-1]) return false;
        char t=s1[n1-1];
        if (t=='a' || t=='e' || t=='i' || t=='o' || t=='u') kg++;
        n1--;
        n2--;
    }
    if (kg<k) return false;
    return true;
}

int main()
{
    scanf("%d %d\n",&n,&k);
    int curt=-1;
    for (int i=1;i<=n;i++)
    {
        gets(s1);
        gets(s2);
        gets(s3);
        gets(s4);
        if (eq(s1,s2) && eq(s2,s3) && eq(s3,s4))
        {
            continue;
        } else if (eq(s1,s2) && eq(s3,s4))
        {
            if (curt==-1) curt=1;
            if (curt!=1) bad();
        } else if (eq(s1,s3) && eq(s2,s4))
        {
            if (curt==-1) curt=2;
            if (curt!=2) bad();
        } else if (eq(s1,s4) && eq(s2,s3))
        {
            if (curt==-1) curt=3;
            if (curt!=3) bad();
        } else bad();
    }
    if (curt==-1) cout << "aaaa" << endl;
    if (curt==1) cout << "aabb" << endl;
    if (curt==2) cout << "abab" << endl;
    if (curt==3) cout << "abba" << endl;
    return 0;
}