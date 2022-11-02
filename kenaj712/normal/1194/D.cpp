#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,k;
        cin>>a>>k;
        if(k%3!=0)
        {
            if(a%3==0)
                cout<<"Bob";
            else
                cout<<"Alice";
        }
        else
        {
            a++;
            a%=(k+1);
            if(a==0||a%3!=1)
                cout<<"Alice";
            else
                cout<<"Bob";
        }
        cout<<'\n';
    }
	return 0;
}