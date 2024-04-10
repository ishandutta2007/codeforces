#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
double a[100009];
ll  n,su;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];su+=floor(a[i]);}
    for(int i=0;i<n;i++)
    {
        if(floor(a[i])==ceil(a[i])||su==0){cout<<floor(a[i])<<"\n";continue;}
           ll q=ceil(a[i]);
           cout<<q<<"\n";
        su++;

    }
    return 0;
}