#include <iostream>
#include <cstdio>

using namespace std;

char s[100005];

int main()
{
    int n;
    scanf("%d%s" , &n , &s);
    int x = 0 , y = 0 ;bool isup=false; int res=0;
    if(s[0]=='U')isup=true,y++;
    else x++;

    for(int i=1 ; i<n ; i++)
    {
        if(s[i] == 'U')
            y++;
        else
            x++;
        if(isup&&x>y) res++,isup=false;
        else if(!isup&&x<y)res++,isup=true;

    }
    cout<<res;
    return 0;
}
/*
int main()
{
    int n;
    scanf("%d" , &n);
    int sum = 0;
    for(int i=1 ; i<n ; i++)
        if(n%i == 0)
            sum++;
    printf("%d" , sum);
    return 0;
}
*/