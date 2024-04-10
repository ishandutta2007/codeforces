#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
int t;
cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)cout<<"(";
            for(int j=0;j<i;j++)cout<<")";
            for(int j=i;j<n;j++)cout<<"()";
            cout<<endl;

        }

    }


  return 0;
}