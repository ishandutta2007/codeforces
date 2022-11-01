#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,a[2000];
vector<int>v1,v2;

int main()
{
    cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        v1.push_back(min(a[i],a[i-1]));
        v2.push_back(max(a[i],a[i-1]));
    }
    for(int i=0;i<v1.size();i++)
        for(int j=0;j<i;j++)
        {
            if(v1[i]<v1[j] && v2[i]<v2[j] && v2[i]>v1[j])
            {
                cout<<"yes"<<endl;
                return 0;
            }
            if(v1[j]<v1[i] && v2[j]<v2[i] && v2[j]>v1[i])
            {
                cout<<"yes"<<endl;
                return 0;
            }
        }
    cout<<"no"<<endl;
}