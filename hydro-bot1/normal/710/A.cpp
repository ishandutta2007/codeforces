// Hydro submission #62550cddac286d0a56b86a87@1649741022478
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s;int x,y;
    cin>>s>>y;x=s-96;
    if(x>1&&x<8&&y>1&&y<8)
    printf("8\n");
    else if((x==1||x==8)&&(y==1||y==8))
    printf("3\n");
    else printf("5\n");
    return 0;
}