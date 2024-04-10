#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    char a[1000],c='a';
    int m,i;
    cin>>a;
    m=strlen(a);
    for(i=0;i<m;i++)
    {
       if(a[i]==c) c++;
       else if(a[i]<c);
       else {cout<<"NO";exit(0);}
    }
    cout<<"YES";
    return 0;
}