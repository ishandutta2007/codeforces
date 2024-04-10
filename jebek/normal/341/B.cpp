#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long n,a,k;
vector<long long>v;

int main()
{
    cin>>n;
    cin>>a;
    v.push_back(a);
    for(int i=1;i<n;i++)
    {
        cin>>a;
        if(a>v[v.size()-1])
            v.push_back(a);
        else
        {
            k=lower_bound(v.begin(),v.end(),a)-v.begin();
            v[k]=a;
        }
    }
    cout<<v.size()<<endl;
}