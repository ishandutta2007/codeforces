#include<iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string num;
        cin >> num;
        if(num.length()==2&&num[0]>=num[1])
        {
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<num[0]<<" ";
            for(int i = 1 ; i < num.length() ; i++)
            {
                cout<<num[i];
            }
            cout<<endl;
        }
    }
    return 0;
}