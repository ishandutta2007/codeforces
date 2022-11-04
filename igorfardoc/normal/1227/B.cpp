#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        bool * mass = new bool[n + 1];
        for(int j = 0; j <= n; j++)
        {
            mass[j] = false;
        }
        int min1 = 1;
        int * ret = new int[n];
        cin >> ret[0];
        mass[ret[0]] = true;
        int maxnow = ret[0];
        bool ok = true;
        for(int j = 1; j < n; j++)
        {
            int now;
            cin >> now;
            if (ok)
            {
                if(now > maxnow)
                {
                    ret[j] = now;
                    maxnow = now;
                    mass[now] = true;
                }
                else
                {
                    while(min1 <= n && mass[min1])
                    {
                        min1++;
                    }
                    if(mass[min1] || min1 >= now)
                    {
                        ok = false;
                    }
                    else
                    {
                        ret[j] = min1;
                        mass[min1] = true;
                    }
                }
            }
        }
        if(ok)
        {
            for(int j = 0; j < n; j++)
            {
                cout << ret[j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}