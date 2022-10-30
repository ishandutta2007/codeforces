#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n,sum,x,p;
vector<int>v1,v2;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        if(x>0){
            p=0;
            v1.push_back(x);
        }
        else{
            p=1;
            v2.push_back(-x);
        }
    }
    if(sum>0)
        cout<<"first"<<endl;
    else if(sum<0)
        cout<<"second"<<endl;
    else
    {
        for(int i=0;i<min(v1.size(),v2.size());i++)
        {
            if(v1[i]<v2[i])
            {
                cout<<"second"<<endl;
                return 0;
            }
            if(v1[i]>v2[i])
            {
                cout<<"first"<<endl;
                return 0;
            }
        }
        if(p==0)
            cout<<"first"<<endl;
        else
            cout<<"second"<<endl;
    }
}