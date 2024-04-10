#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int licz=0;
    int c;
    cin>>c;
    string a,b;
    cin>>a>>b;
    for(int x=0;x<c;x++)
    {
        if(x!=c-1)
        {
            if(a[x]!=b[x])
            {
                if(a[x+1]!=b[x+1]&&a[x]!=a[x+1])
                    swap(a[x],a[x+1]);
                licz++;
            }
        }
        else
        {
            if(a[x]!=b[x])
                licz++;
        }
    }
    cout<<licz;
	return 0;
}