// Hydro submission #626778cd255d14008c299ba0@1650948301836
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        switch(s[s.size()-1])
        {
            case 97:printf("KOREAN\n");break;
            case 111:printf("FILIPINO\n");break;
            case 117:printf("JAPANESE\n");break;
        }
    }
    return 0;
}