#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        long long maks=0,suma=0;
        for(int x=0;x<a;x++)
        {
            cin>>tab[x];
            suma+=tab[x];
            maks=max(maks,tab[x]);
        }
        if(a==1)
            cout<<"T"<<'\n';
        else if(a==2)
        {
            if(tab[0]==tab[1])
                cout<<"HL"<<'\n';
            else
                cout<<"T"<<'\n';
        }
        else
        {
            if(maks*2>suma || suma%2==1)
                cout<<"T"<<'\n';
            else
                cout<<"HL"<<'\n';
        }
    }
	return 0;
}