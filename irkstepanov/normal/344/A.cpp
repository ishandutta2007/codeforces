#include <iostream>
#include <string>

using namespace std;

int main()
{

    int kol = 0;
    int n;
    cin >> n;
    string prev = "";

    while (n--)
    {
        string s;
        cin >> s;
        if (prev == s) prev = s;
        else {++kol; prev = s;}
    }

    cout << kol;

}