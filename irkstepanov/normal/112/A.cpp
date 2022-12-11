#include <iostream>
#include <string>

using namespace std;

int main()
{

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] = (char) ((a[i] - 'A') + 'a');
        if (b[i] >= 'A' && b[i] <= 'Z') b[i] = (char) ((b[i] - 'A') + 'a');
    }

    if (a > b) cout << "1";
    else if (a == b) cout << "0";
    else cout << "-1";

}