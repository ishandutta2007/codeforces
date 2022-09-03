#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 9; i++)
        {
            string S;
            cin >> S;
            S[i * 4 % 9] = (S[i * 4 % 9] == '1' ? '2' : '1');
            printf("%s\n", S.c_str());
        }
    }
}