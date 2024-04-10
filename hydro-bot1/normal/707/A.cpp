// Hydro submission #62550cb9ac286d0a56b86a01@1649740986271
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;char c;
    cin>>n>>m;
    for(i=0;i<n*m;i++)
    {
        cin>>c;
        if(c==67||c==77||c==89)
        {
            printf("#Color\n");
            return 0;
        }
    }
    printf("#Black&White\n");
    return 0;
}