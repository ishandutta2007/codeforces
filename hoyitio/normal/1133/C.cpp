#include<iostream>
#include <string.h>
#include <algorithm>
#include<cstdio>

using namespace std;
int a[200010];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l = 1;
    int maxx = 0;
    int len = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i] - a[l] <= 5)
        {
            len = i - l+1;
        }else{
            while(a[i] - a[l] >5){
                l++;
            }
            len = i - l+1;
        }
        if(len > maxx)
        {
            maxx = len;
        }
    }
    cout<<maxx<<endl;
    return 0;
}