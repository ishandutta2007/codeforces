#include <iostream>

using namespace std;

int main()
{   int n;
    cin>>n;
    int ik,jk;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin>>ik>>jk;
        if(jk-ik>1)
            ans++;
    }
    cout<< ans;



}