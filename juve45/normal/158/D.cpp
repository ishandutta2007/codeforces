#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int n, a[20009], s, S;

void Factor(int n)
{
    int i;

    if(n%2==0 && n!=4)
        v.push_back(2);

    for(i=3; i*i<n; i++)
    {
        if(n%i==0) v.push_back(i),v.push_back(n/i);
    }
    if(i*i==n && i!=2)
        v.push_back(i);

}

int Sum(int k, int pos)
{
    int ans=0;
    for(int i=pos; i<=n; i+=k)
        ans+=a[i];
    return ans;
}

int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i], S+=a[i];

    Factor(n);

    for(int i=0; i<v.size(); i++)
    {
        for(int pos=1; pos<=v[i]; pos++)
        {
            int s=Sum(v[i], pos);
            if(s>S)
                S=s;
        }
    }
    cout<<S<<'\n';
    return 0;
}