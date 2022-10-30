// Hydro submission #625cee5281ef68d42bcbb30e@1650257491499
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,t=0,i;
    string s;
    cin>>k>>s;
    if(k%2)
    {
        printf("1\n");
        cout<<s<<endl;
    }
    else
    {
        for(i=0;i<k;i++)
        if(s[i]==48) t++;
        if(k-t*2)
        {
            printf("1\n");
            cout<<s<<endl;
        }
        else
        {
            printf("2\n%c ",s[0]);
            for(i=1;i<k;i++)
            printf("%c",s[i]);
        }
    }
    
    return 0;
}