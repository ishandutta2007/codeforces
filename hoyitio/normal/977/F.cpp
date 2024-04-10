#include<iostream>
#include<map>
#include<stack>
#include<cstdio>

using namespace std;

const int MAXN = 2e5+10;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    int num = 0;
    int last = 0;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]] = mp[a[i]-1]+1;
        if(mp[a[i]] > num)
        {
            num = mp[a[i]];
            last = a[i];
        }
    }
    stack<int> s;
    for(int i = n ; i >= 0 ; i--)
    {
        if(a[i] == last)
        {
            s.push(i+1);
            last--;
        }
    }
    printf("%d\n",s.size());
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}