#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int x,y;
    cin>>x>>y;
    for(int i=x;i<=y;i++)
    {
        set<int> s;
        int k = i,cnt = 0;
        while(k){
            s.insert(k%10);
            k =k/10;
            cnt++;
        }
        if(s.size() == cnt){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;


    return 0;
}