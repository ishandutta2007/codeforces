#include <iostream>
using namespace std;

int m[100009];

int main()
{
    int n, a, b;
    cin>>n;
    for (int i = 1; i < n; i++){
        cin>>a>>b;
        m[a]++; m[b]++;
    }
    int f = 0, r = 0;
    for (int i = 1; i <= n; i++){
        if (m[i] > 2 && f == 0){
            f = 1;
            r = i;
        }
        else if (m[i] > 2){
            cout<<"No"<<'\n';
            return 0;
        }
    }
    cout<<"Yes"<<'\n';
    if (r == 0){
        cout<<1<<'\n';
        for (int i = 1; i <= n; i++)
            if (m[i] == 1)
                cout<<i<<" ";
        cout<<'\n';
    }
    else{
        int c = 0;
        for (int i = 1; i <= n; i++)
            if (m[i] == 1)
                c++;
        cout<<c<<'\n';
        for (int i = 1; i <= n; i++)
            if (m[i] == 1)
                cout<<r<<" "<<i<<'\n';
    }
    return 0;
}