// Screw this ..
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    for (; q; q --)
    {
        int n;
        string S;
        cin >> n >> S;
        int df = 0;
        for (int i = 0; i < n; i ++)
            if (S[i] != S[i - 1])
                df = 1;
        if (!df)
            {cout << S << endl; continue;}
        vector < pair < int , int > > vec;
        vec.push_back({1, S[0] - '0'});
        for (int i = 1; i < n; i ++)
            if (S[i] == S[i - 1])
                vec.back().first ++;
            else
                vec.push_back({1, S[i] - '0'});
        string PR, SF, Rs;
        if (vec.back().second == 1)
            SF = string(vec.back().first, '1'), vec.pop_back();
        if (vec.size() && vec[0].second == 0)
            PR = string(vec[0].first, '0'), vec.erase(vec.begin());
        if (vec.size() > 1)
            Rs = "0";
        else if (vec.size() == 1)
            Rs = "1";
        Rs = PR + Rs + SF;
        cout << Rs << endl;
    }
    return 0;
}