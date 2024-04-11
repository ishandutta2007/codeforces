#include <bits/stdc++.h>
using namespace std;

int A[10];
int main()
{
    int n;
    string s;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>s;
        if (s=="purple")
            A[1]=1;
        if (s=="blue")
            A[3]=1;
        if (s=="green")
            A[2]=1;
        if (s=="orange")
            A[4]=1;
        if (s=="red")
            A[5]=1;
        if (s=="yellow")
            A[6]=1;
    }
    cout<<6-n<<"\n";
    if (A[1]==0)
        cout<<"Power"<<"\n";
    if (A[2]==0)
        cout<<"Time"<<"\n";
    if (A[3]==0)
        cout<<"Space"<<"\n";
        if (A[4]==0)
        cout<<"Soul"<<"\n";
        if (A[5]==0)
        cout<<"Reality"<<"\n";
        if (A[6]==0)
        cout<<"Mind"<<"\n";
    return 0;
}