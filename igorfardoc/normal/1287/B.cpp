#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    set<string> s;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    long long ans = 0;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        auto it1 = it;
        for(it1++; it1 != s.end(); it1++)
        {
            string need = "";
            for(int i = 0; i < k; i++)
            {
                if((*it)[i] == (*it1)[i])
                {
                    need += (*it)[i];
                }
                else
                {
                    need += 'S' + 'E' + 'T' - (*it)[i] - (*it1)[i];
                }
            }
            if(s.find(need) != s.end())
            {
                ans++;
            }
        }
    }
    cout << ans / 3;
}