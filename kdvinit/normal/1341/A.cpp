#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int x=n*(a-b);
        int y=n*(a+b);
        if(x>c+d) cout<<"NO"<<endl;
        else if (y<c-d) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

        t--;
    }
    return 0;
}