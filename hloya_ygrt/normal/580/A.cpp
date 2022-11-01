#include <iostream>

using namespace std;

int a[100000];
int main()
{
    int n;
    cin>>n;
    int _max=1,t=1;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    for (int i=1;i<n;i++){
        if (a[i]>=a[i-1]){
            t++;
            if (_max<t) _max=t;
        } else t=1;
    }
    cout<<_max;
    return 0;
}