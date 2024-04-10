#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    if(A>B)
        swap(A,B);
    cout<<A<<" "<<(B-A)/2<<endl;
    return 0;
}