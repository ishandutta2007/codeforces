//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

string ans[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

void test()
{
   int n;
   cin >> n;
   string x;
   cin >> x;
   for(int i=0; i<8; i++)
        if(ans[i].size()==n)
        {
            bool czy = true;
            for(int j=0; j<n; j++)
            {
                if(x[j]=='.')
                    continue;
                if(x[j]!=ans[i][j])
                {
                    czy = false;
                    break;
                }
            }
            if(czy)
            {
                cout << ans[i];
                break;
            }
        }
    
    
}

int main()
{
    test();
    return 0;
}