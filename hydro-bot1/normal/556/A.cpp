// Hydro submission #6255069fac286d0a56b85d5d@1649739423981
#include<bits/stdc++.h>
using namespace std;
int s0,s1;
int main()
{
    string s;
    int l,i;
    cin>>l>>s;
    for(i=0;i<l;i++)
    if(s[i]==48) s0++;
    else s1++;
    printf("%d\n",abs(s0-s1));
    return 0;
}