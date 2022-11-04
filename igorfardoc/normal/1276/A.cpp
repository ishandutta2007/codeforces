#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        string str;
        cin >> str;
        vector<int> ans(0);
        int i = 0;
        while(i < ((int)str.length() - 2))
        {
            if(i < (int)str.length() - 4)
            {
                if(str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o' && str[i + 3] == 'n' && str[i + 4] == 'e')
                {
                    ans.push_back(i + 3);
                    i += 5;
                    continue;
                }
            }
            if(str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e')
            {
                ans.push_back(i + 2);
                i += 3;
                continue;
            }
            if(str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o')
            {
                ans.push_back(i + 2);
                i += 3;
                continue;
            }
            i++;
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}