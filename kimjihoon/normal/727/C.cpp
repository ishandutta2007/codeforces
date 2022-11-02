#include <iostream>
using namespace std;

int main()
{
    int n, a[9999], t;
    cin>>n;
    cout<<"? 1 2"<<endl;
    cin>>a[1];
    cout<<"? 2 3"<<endl;
    cin>>a[2];
    cout<<"? 1 3"<<endl;
    cin>>a[3];
    a[1] = ((a[1]+a[3])-a[2])/2; a[3] -= a[1]; a[2] -= a[3];
    for (int i = 4; i <= n; i++){
        cout<<"? 1 "<<i<<endl;
        cin>>t;
        a[i] = t - a[1];
    }
    cout<<"!";
    for (int i = 1; i <= n; i++)
        cout<<" "<<a[i];
    cout<<endl;
    return 0;
}