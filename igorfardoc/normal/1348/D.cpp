#include<bits/stdc++.h>
using namespace std;

void print(vector<long long> & mass)
{
    long long now = 1;
    cout << mass.size() << endl;
    for(int i = 0; i < mass.size(); i++)
    {
        if(i == 0)
        {
            cout << mass[i] - 1 << " ";
        }
        else
        {
            cout << mass[i] - mass[i - 1] << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        long long n;
        cin >> n;
        vector<long long> mass;
        long long nowsum = 1;
        long long now = 1;
        bool ok = false;
        while(true)
        {
            now *= 2;
            mass.push_back(now);
            nowsum += now;
            if(nowsum == n)
            {
                print(mass);
                ok = true;
                break;
            }
            if(nowsum > n)
            {
                break;
            }
        }
        if(ok)
        {
            continue;
        }
        for(int i = mass.size() - 1; i >= 0; i--)
        {
            if((mass[i] >> 1) < nowsum - n)
            {
                mass[i] = mass[i] >> 1;
                nowsum -= mass[i];
            }
            else
            {
                mass[i] -= nowsum - n;
                break;
            }
        }
        print(mass);
    }
}