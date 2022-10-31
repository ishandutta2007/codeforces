// Hydro submission #6253d444ca5306014671740b@1649660997562
#include<bits/stdc++.h>
using namespace std;
int n,i,e,t,mn=20;
int main()
{
    string c;
    cin>>c;
    for(int j=0;j<c.size();j++)
    switch(c[j])
    {
        case 'n':n++;break;
        case 'i':i++;break;
        case 't':t++;break;
        case 'e':e++;break;
    }
    printf("%d\n",min(min(min(min(mn,e/3),i),(n-1)/2),t));
    return 0;
}