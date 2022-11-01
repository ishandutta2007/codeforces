#include <bits\stdc++.h>

using namespace std;

    const int maxn=2e5;
    const int inf=2e9;
    const int eps=1e-5;

#define pb push_back
#define mp make_pair
#define fir first
#define m month
#define sec second
    int month[12],day[7]={0};
int main()
{
    int n;
    char c;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d of %c",&n,&c);

    m[0]=31;
    m[1]=29;
    m[2]=31;
    m[3]=30;
    m[4]=31;
    m[5]=30;
    m[6]=31;
    m[7]=31;
    m[8]=30;
    m[9]=31;
    m[10]=30;
    m[11]=31;

    if (c=='m')
    {
        if (n<=29)
            cout<<12;
        else
            if (n==30)
            cout<<11;
        else
            cout<<7;
            return 0;
    }
    int day1=4;

    for (int i=0;i<366;i++)
    {
        day[day1]++;
        day1++;
        if (day1==7)
            day1=0;
    }
    cout<<day[n-1];
    return 0;
}