// Hydro submission #625920bfcc64917dc46653d5@1650008255767
#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    for(int i=0;i<6;i++)
    {
        printf("%d\n",i);
        cin>>a; 
        if(a[0]=='w'||a[0]=='a'||a[2]==' ')
        {
            printf("grumpy\n");
            return 0;
        }
    }
    printf("normal\n");
    return 0;
}