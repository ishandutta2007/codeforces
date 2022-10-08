#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
string cards[MAXN];
string tips = "12345RGYBW";
set <char> S;

bool check(int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(cards[i]==cards[j])
                continue;
            int k = 0;
                if(cards[i][k] != cards[j][k])
                    if(S.find(cards[i][k])!=S.end() || S.find(cards[j][k])!=S.end())
                        continue;
            k = 1;
                if(cards[i][k] != cards[j][k])
                    if(S.find(cards[i][k])!=S.end() || S.find(cards[j][k])!=S.end())
                        continue;
            //cout << i << " " << j << "\n";
            return false; 
        }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, wyn = 19;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> cards[i];
    for(int mas=0; mas<(1<<10); mas++)
    {
        int k = 0;
        S.clear();
        for(int i=0; i<10; i++)
            if((mas & (1<<i)))
            {
                S.insert(tips[i]);
                //cout << tips[i];
                k++;
            }
        //cout << "\n";
        if(check(n))
        {
            //cout << "HERE\n";
            wyn = min(wyn, k);
        }
    }
    cout << wyn;
    return 0;
}