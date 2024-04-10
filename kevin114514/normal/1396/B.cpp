#include<bits/stdc++.h>
using namespace std;
int x[110];
void Solve()
{
    int n;
    cin>>n;
    int Sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        Sum+=x[i];
    }
    sort(x,x+n);
    reverse(x,x+n);
    int last=-1;
    for(int i=0;i<Sum;i++)
    {
        bool find=false;
        for(int j=0;j<n;j++)
            if(j!=last&&x[j])
            {
                x[j]--;
                last=j;
                find=true;
                break;
            }
        if(!find)
        {
            if(i%2)
                puts("T");
            else    puts("HL");
            return ;
        }
        int tmp=x[last];
        sort(x,x+n);
        reverse(x,x+n);
        for(int j=0;j<n;j++)
            if(x[j]==tmp)
            {
                last=j;
                break;
            }
    }
    if(Sum%2)
        puts("T");
    else    puts("HL");
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        Solve();
    return 0;
}