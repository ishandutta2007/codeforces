#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool check(int x)
{
    int j=0;
    while(1<<j&x) j++;
    while(j<20)
    {
        if(1<<j&x) return false;
        j++;
    }
    return true;
}
int main()
{
    int x;
    scanf("%d",&x);
    int ans=0;
    while(!check(x))
    {
        ans++;
        if(ans%2)
        {
            int j=20;
            while(j>=0)
            {
                if(1<<j&x) break;
                j--;
            }
            int n=0;
            v.push_back(j+1);
            while(j>=0)
                n+=1<<j,j--;
            x^=n;
        }
        else
            x++;
    }
    printf("%d\n",ans);
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
}