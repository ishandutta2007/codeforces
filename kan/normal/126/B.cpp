#include <iostream>
#include <string>

using namespace std;

const int maxn=1000005;

int p[maxn],was[maxn];

int main()
{
    string s;
    cin >> s;
    s='#'+s;
    int n=s.length();
    p[1]=0;
    int k=0;
    for (int i=2;i<n;i++)
    {
        while ((k>0)&&(s[k+1]!=s[i])) k=p[k];
        if (s[k+1]==s[i]) k++;
        p[i]=k;
        if (i!=n-1) was[k]=1;
    }
    k=p[n-1];
    while (k>0)
    {
        if (was[k]==1)
        {
            for (int i=1;i<=k;i++) cout << s[i];
            return 0;
        }
        k=p[k];
    }
    cout << "Just a legend";
    return 0;
}