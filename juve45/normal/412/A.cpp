#include <bits/stdc++.h>
#define DMAX 120
using namespace std;
int n, k;
char s[DMAX];

void go_left()
{
    while(k!=1)
    {
        printf("LEFT\n");
        k--;
    }
    for(int i=1;i<=n;i++)
        if(i!=n)
        printf("PRINT %c\nRIGHT\n", s[i]);
    else printf("PRINT %c\n", s[i]);
}

void go_right()
{
    while(k!=n)
    {
        printf("RIGHT\n");
        k++;
    }
    for(int i=n;i>0;i--)
    {
        if(i>1)
        printf("PRINT %c\nLEFT\n", s[i]);
        else printf("PRINT %c\n", s[i]);
    }
}

int main()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>s[i];

    if(k<=n/2)
        go_left();
    else go_right();

    return 0;
}