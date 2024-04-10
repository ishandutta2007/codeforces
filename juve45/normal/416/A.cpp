#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int st=-1000000002, dr=1000000002, n, k;

int main()
{
char s[5], a;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s>>k>>a;
        if(a=='N')
        {
            if(strcmp(s, "<")==0)
            st=max(k, st);
            if(strcmp(s, "<=")==0)
            st=max(k+1, st);
            if(strcmp(s, ">")==0)
                dr=min(k, dr);
            if(strcmp(s, ">=")==0)
            dr=min(k-1, dr);
                        }
                        if(a=='Y')
        {
            if(strcmp(s, ">")==0)
            st=max(k+1, st);
            if(strcmp(s, ">=")==0)
            st=max(k, st);
            if(strcmp(s, "<")==0)
                dr=min(k-1, dr);
            if(strcmp(s, "<=")==0)
            dr=min(k, dr);
                        }

    }
    if(st<=dr)
cout<<st;
else cout<<"Impossible";
    return 0;
}