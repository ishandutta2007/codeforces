// Hydro submission #62550ccbac286d0a56b86a3f@1649741003630
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,d,a,i,s=0,t=0;
    cin>>n>>b>>d;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a<=b)
        {
            s+=a;
            if(s>d)
            {
                s=0;
                t++;
            }
        }
    }
    printf("%d\n",t);
    return 0;
}