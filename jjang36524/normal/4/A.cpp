#include <iostream>
int N;
using namespace std;
int main()
{
    cin >> N;
    if(N>2&&!(N%2))
    cout << "YES";
    else
    cout <<"NO";
}