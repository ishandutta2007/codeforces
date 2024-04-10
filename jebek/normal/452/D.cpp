#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

queue<long long>d[3];
long long k,n1,n2,n3,t1,t2,t3,x;

int main()
{
    cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
   // cout<<d[2].size()<<endl;
    for(int i=1;i<=k;i++)
    {
        if(d[0].size()<n1 && d[1].size()<n2 && d[2].size()<n3)
        {
           // cout<<x<<endl;
            d[0].push(x+t1);
            d[1].push(x+t2);
            d[2].push(x+t3);
            continue;
        }
        if(d[0].size() && (d[1].size()==0 || d[0].front()<=d[1].front())&& (d[2].size()==0 || d[0].front()<=d[2].front()))
        {
            x=d[0].front();
            d[0].pop();
        }
        else if(d[1].size() && (d[0].size()==0 || d[1].front()<=d[0].front())&& (d[2].size()==0 || d[1].front()<=d[2].front()))
        {
            x=d[1].front();
            d[1].pop();
        }
        else
        {
            x=d[2].front();
            d[2].pop();
        }
        i--;
    }
    cout<<x+t1+t2+t3<<endl;
}