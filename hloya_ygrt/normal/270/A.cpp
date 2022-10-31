#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t; i++ ) {
        int s;
        cin >> s;
        if (360 % (180-s) == 0) cout<< "YES"<<endl;
        else
            cout << "NO" <<endl;
    }
    return 0;
}