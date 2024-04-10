#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            cout<<"? 1 "<<mid<<endl;
            fflush(stdout);
            int x,c=0;
            for(int i=0;i<mid;i++)
            {
                cin>>x;
                if(x<=mid)c++;
            }
            if(c%2)r=mid;
            else l=mid+1;


        }
        cout<<"! "<<l<<endl;
        fflush(stdout);


}
    return 0;
}