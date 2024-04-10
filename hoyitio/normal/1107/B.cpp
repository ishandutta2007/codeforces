#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    while(n--)
    {
        long long k,x;
        cin >> k >> x;
        cout<<x+(k-1)*9<<endl;
//        if(x==1)
//        {
//            if(k==1)
//            {
//                cout<<1<<endl;
//            }
//            else{
//                cout<<1+(k-1)*9<<endl;
//            }
//        }else{
//            if(k==1)
//            {
//                cout<<x<<endl;
//            }
//            else{
//                cout<<x+(k-1)*9<<endl;
//            }
//        }
    }
    return 0;
}