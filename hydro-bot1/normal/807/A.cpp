// Hydro submission #62baa5fe5ffd6a7e32a8b0c3@1656399358413
#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    int n,a,b,c=4127,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a!=b)
        {
            printf("rated\n");
            return 0;
        }
        if(a>c)
        f=true;
        c=a;
    }
    printf(f?"unrated\n":"maybe\n");
    return 0;
}