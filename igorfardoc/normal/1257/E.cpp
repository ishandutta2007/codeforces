#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int * mass = new int[k1 + k2 + k3];
    int ** dp = new int*[k1 + k2 + k3];
    for(int i = 0; i < k1; i++)
    {
        int a;
        cin >> a;
        mass[a - 1] = 0;
        dp[i] = new int[3];
    }
    for(int i = 0; i < k2; i++)
    {
        int a;
        cin >> a;
        mass[a - 1] = 1;
        dp[i + k1] = new int[3];
    }
    for(int i = 0; i < k3; i++)
    {
        int a;
        cin >> a;
        mass[a - 1] = 2;
        dp[i + k1 + k2] = new int[3];
    }
    if(mass[0] == 0)
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
    }
    else if(mass[0] == 1)
    {
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
    }
    else
    {
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 0;
    }
    for(int i = 1; i < k1 + k2 + k3; i++)
    {
        if(mass[i] == 0)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = 1 + min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
        else if(mass[i] == 1)
        {
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = 1 + min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
        else
        {
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
    }
    cout << min(min(dp[k1 + k2 + k3 - 1][0], dp[k1 + k2 + k3 - 1][1]), dp[k1 + k2 + k3 - 1][2]);
}