#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        char str[100];
        scanf("%s",str);
        vector<pair<int,int> >mp;
        for(int i=12;i>0;i--)
        {
            if(12%i==0)
            {
                bool flag=true;
                for(int k=0;k<i;k++)
                {
                    flag=true;
                    for(int j=k;j<12;j+=i)
                    {
                        if(str[j]!='X')
                            flag=false;
                    }
                    if(flag)
                    {
                        mp.push_back(make_pair(12/i,i));
                        break;
                    }
                }
            }
        }
        printf("%d",mp.size());
        for(int i=0;i<mp.size();i++)
            printf(" %dx%d",mp[i].first,mp[i].second);
        printf("\n");
    }
    return 0;
}