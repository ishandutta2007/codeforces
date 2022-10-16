#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(min(a,b)>max(c,d)||min(c,d)>max(a,b))
            puts("NO");
        else    puts("YES");
    }
    return 0;
}