#include<iostream>

using namespace std;
const int MAXN = 1e4+10;
int cnt[MAXN];
int main()
{
    int n;
    int x = 0,y = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        int t;
        cin >>t;
        cnt[t]++;
        x = max(x,t);
    }
    for(int i = 1 ; i <= x ; i++)
    {
        if(x%i==0)
        {
            cnt[i]--;
        }
    }
    y = x;
    while(!cnt[y])
    {
        y--;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}