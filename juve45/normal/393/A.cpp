#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ni, nn, ne, nt;
char s[104];

int main()
{
cin>>s;
int lg=strlen(s);

for(int i=0; i<lg;i++)
{
    if(s[i]=='i')
        ni++;

    if(s[i]=='e')
        ne++;

    if(s[i]=='t')
        nt++;

    if(s[i]=='n')
        nn++;
}
nn=(nn-1)/2;
ne=ne/3;
cout<<min(min(ni, ne),min(nn, nt));
    return 0;
}