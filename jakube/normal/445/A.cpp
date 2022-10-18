#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int j = 0;
        for (char c : s)
        {
            if (c == '.')
            {
                if ((i + j) % 2)
                    cout << "B";
                else
                    cout << "W";
            }
            else
                cout << c;
            j++;
        }
        cout << endl;
    }
}