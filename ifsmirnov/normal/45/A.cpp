#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

string mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int main()
{
    string t;
    cin >> t;
    int cur;
    for (int i = 0; i < 12; i++)
        if (mon[i] == t)
            cur = i;
    int n;
    cin >> n;
    cur = (cur + n) % 12;
    cout << mon[cur];
    return 0;
}