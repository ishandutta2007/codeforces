#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

map<string, vector<string> > pred;

void init()
{
    string foo[5] = {"S", "M", "L", "XL", "XXL"};
    pred["S"] = vector<string> (foo, foo + 5);

    string foo2[5] = {"M", "L", "S", "XL", "XXL"};
    pred["M"] = vector<string> (foo2, foo2 + 5);

    string foo3[5] = {"L","XL", "M", "XXL", "S"};
    pred["L"] = vector<string> (foo3, foo3 + 5);

    string foo4[5] = {"XL", "XXL", "L", "M", "S"};
    pred["XL"] = vector<string> (foo4, foo4 + 5);

    string foo5[5] = {"XXL", "XL", "L", "M", "S"};
    pred["XXL"] = vector<string> (foo5, foo5 + 5);
};

map<string, int> vals;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    int tmp;
    cin >> tmp;
    vals["S"] = tmp;
    cin >> tmp;
    vals["M"] = tmp;
    cin >> tmp;
    vals["L"] = tmp;
    cin >> tmp;
    vals["XL"] = tmp;
    cin >> tmp;
    vals["XXL"] = tmp;

    int k;
    cin >> k;
    string t;
    for (int i = 0; i < k; i++)
    {
        cin >> t;
        for (int j = 0; j < 5; j++)
        {
            if (vals[pred[t][j]])
            {
                vals[pred[t][j]]--;
                cout << pred[t][j] << endl;
                break;
            }
        }
    }
    return 0;
}