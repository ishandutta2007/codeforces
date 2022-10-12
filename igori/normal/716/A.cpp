#include <iostream>

using namespace std;

int main()
{
    int a[100000];
    int n;
    int c;
    cin>>n>>c;
    int now=0;
    int t=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        now++;
        if(i>0)
        if(a[i]-a[i-1]>c)
            {now=0;t++;}
    }
    if(t==0)
    cout<<now;
    else
        cout<<now+1;
}