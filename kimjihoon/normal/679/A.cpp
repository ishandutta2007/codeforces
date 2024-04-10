#include <iostream>
using namespace std;
string s;
int v[99], c;
int main()
{
    for (int i = 2; i <= 50; i++){
        if (v[i] == 0){
            cout<<i<<endl;
            cin>>s;
            if (s == "yes")
                c++;
            if (c >= 2){
                cout<<"composite"<<endl;
                return 0;
            }
            if (i*i <= 50){
                cout<<i*i<<endl;
                cin>>s;
                if (s == "yes"){
                    cout<<"composite"<<endl;
                    return 0;
                }
            }
            for (int j = i; j <= 50; j += i)
                v[j] = 1;
        }
    }
    cout<<"prime"<<endl;
    return 0;
}