#include <iostream>
#include <vector>
using namespace std;

vector<int> va, vb;

int main()
{
    int a, b;
    cin>>a>>b;
    int r = 1, s = 1;
    while (s <= a + b){
        r++; s += r;
    }
    r--;
    for (int i = r; i >= 1; i--){
        if (i <= a){
            a -= i;
            va.push_back(i);
        }
        else
            vb.push_back(i);
    }
    cout<<va.size()<<'\n';
    for (int i = 0; i < va.size(); i++)
        cout<<va[i]<<" ";
    cout<<'\n';
    cout<<vb.size()<<'\n';
    for (int i = 0; i < vb.size(); i++)
        cout<<vb[i]<<" ";
    cout<<'\n';
    return 0;
}