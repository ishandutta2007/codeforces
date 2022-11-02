#include<bits/stdc++.h>
using namespace std;
int days,now,hist,maxn,temp[1000000];
int main()
{
    
    cin>>days;
    for(int i=0;i<days;i++)
    {
        cin>>temp[i];
    }
    for(int j=0;j<days;j++)
    {
        if(temp[j+1]>=temp[j])
        {
            now++;
        }
        else
        {
            hist=now;
            now=0;
            if(hist>maxn)
            {
                maxn=hist;
            }
        }
    }
    maxn++;
    cout<<maxn;
}