#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int n, a[100009], use[100009];

int main()
{
cin>>n;

for(int i=1;i<=n;i++)
    cin>>a[i], use[a[i]]++;

for(int i=1;i<=n;i++)
    if(use[i]==0)
    v.push_back(i);

for(int i=1;i<=n;i++)
{
    if(use[a[i]]>1 || a[i]>n)
    {
        use[a[i]]--;
        a[i]=v.back();
        v.pop_back();
    }
}

for(int i=1;i<=n;i++)
    cout<<a[i]<<' ';

    return 0;
}