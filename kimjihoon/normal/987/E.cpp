#include <iostream>
using namespace std;

int a[1000009];

int main()
{
    int n, c = 0;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n;){
        if (a[i] != i){
            swap(a[i], a[a[i]]);
            c++;
        }
        else
            i++;
    }
    if ((n*3)%2 == c%2)
        cout<<"Petr"<<'\n';
    else
        cout<<"Um_nik"<<'\n';
    return 0;
}