#include<iostream>

using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        long long a,b,k;
        cin >> a >> b >> k;
        long long l = a-b;
        if(k == 1)
        {
            cout<<a<<endl;
        }
        else{
            if(k%2==0)
            {
                cout<<(k/2)*l<<endl;
            }
            else{
                cout<<(k/2)*l+a<<endl;
            }
        }
    }
    return 0;
}