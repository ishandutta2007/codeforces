#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void Do(char zn, int pos, char * mass, vector<pair<int, int> > * op)
{
    if (mass[pos] == zn)
    {
        return;
    }
    int i = pos + 1;
    while(mass[i] != zn)
    {
        i++;
    }
    op->push_back(make_pair(pos + 1, i + 1));
    for(int j = 0; j < (i - pos - 1) / 2 + 1; j++)
    {
        int l = mass[pos + j];
        mass[pos + j] = mass[i - j];
        mass[i - j] = l;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int u = 0; u < t; u++)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        char * mass = new char[n];
        vector<pair<int, int> > op;
        for(int i = 0; i < n; i++)
        {
            mass[i] = str[i];
        }
        for(int i = 0; i < n; i++)
        {
            if (i < (k - 1) * 2)
            {
                if (i % 2 == 0)
                {
                    Do('(', i, mass, &op);
                }
                else
                {
                    Do(')', i, mass, &op);
                }
            }
            else
            {
                if(i < (n - (k - 1) * 2) / 2 + (k - 1) * 2)
                {
                    Do('(', i, mass, &op);
                }
                else
                {
                    Do(')', i, mass, &op);
                }
            }
        }
        cout << op.size() << endl;
        for(int i = 0; i < op.size(); i++)
        {
            cout << op[i].first << " " << op[i].second << endl;
        }
    }
}