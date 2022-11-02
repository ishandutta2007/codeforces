#include <iostream>
using namespace std;
string s;
int main()
{
    int h, m, c = 0;
    cin>>s;
    h = (s[0] - '0')*10 + (s[1] - '0');
    m = (s[3] - '0')*10 + (s[4] - '0');
    for (int i = h; i < 24; i++){
        for (int j = m; j <= 59; j++){
            if ((i%10)*10 + i/10 == j){
                cout<<c<<endl;
                return 0;
            }
            c++;
        }
        m = 0;
    }
    cout<<c<<endl;
    return 0;
}