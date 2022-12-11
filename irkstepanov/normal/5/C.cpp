#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string s;
    cin >> s;

    int n = (int) s.size();

    vector <int> first(n, -1), last(n, -1);

    stack <int> opn;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') opn.push(i);
        else
        {
            if (opn.empty()) first[i] = last[i] = -1;
            else
            {
                first[i] = last[i] = opn.top();
                opn.pop();
                if (s[last[i] - 1] == ')' && first[last[i] - 1] != -1) first[i] = first[last[i] - 1];
            }
        }
    }

    int len = 0, kol = 1;
    for (int i = 0; i < n; i++)
        if (first[i] != -1)
        {
            if (i - first[i] + 1 > len)
            {
                len = i - first[i] + 1;
                kol = 1;
            }
            else if (i - first[i] + 1 == len) ++ kol;
        }

    cout << len << " " << kol;

}